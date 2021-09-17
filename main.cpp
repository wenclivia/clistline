#include <stdio.h>
#include <stdlib.h>
struct link *append(struct link *head);
struct link *del(struct link *head,int node);
struct link *sorted(struct link *head);
struct link *insert(struct link *head,int code);
struct link *insertwithoutqueue(struct link *head,int code);
//注意以struct link开始的函数要有返回值
void display(struct link *head);
void dele(struct link *head);
struct link{
    int num;
    struct link *next;
};
int main(void){
    struct link *head=NULL;
    char c;
    char p;
    int m=1;
    printf("do you want to add a number?(y/n)\n");
    scanf(" %c",&c);
    while(c=='y'||c=='Y'){
        head=append(head);
        display(head);
        printf("do you still want to add a number?(y/n)\n");
        scanf(" %c",&c);
        m++;
    }
    printf("ok,we've already completed the recording,do you wanna sort them?(y/n)\n");
    getchar();
    scanf("%c",&p);
    if(p=='y'||p=='Y'){
        head=sorted(head);
        display(head);
    }
    printf("after checking,do you wanna delete?(y/n)\n");
    char d;
    int l;
    scanf(" %c",&d);
    if(d=='y'||d=='Y'){
        printf("which number do you wanna delete?\n");
        scanf("%d",&l);
        head= del(head,l);
        display(head);
    }
    printf("besides,do u wanna insert some number?(y/n)\n");
    char f,g;
    int code;
    scanf(" %c",&f);
    if(f=='y'||f=='Y'){
        printf("which number u wanna add?\n");
        scanf(" %d",&code);
        printf("do u wanna insert it with queue?(y/n)\n");
        scanf(" %c",&g);
        if(g=='y'||g=='Y'){
            head=insert(head,code);
            display(head);
        }
        else{
            head=insertwithoutqueue(head,code);
            display(head);
        }

    }
    dele(head);
}
struct link *append(struct link *head){
    struct link *p=head,*pr=NULL;
    int num;
    pr=(struct link *)malloc(sizeof(struct link));
    if(pr==NULL){
        printf("nope");
        exit(0);
    }
    if(head==NULL){
        head=pr;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=pr;
    }
    printf("please input the number.\n");
    scanf("%d",&num);
    pr->num=num;
    pr->next=NULL;
    return head;
}
struct link *del(struct link *head,int node){
    struct link *p=head,*pr=head;
    if(head==NULL){
        return head;
    }

    while(node!=p->num&&p->next!=NULL){
        pr=p;
        p=p->next;
    }
    if(node==p->num){
        if(p==head){
            head=p->next;
        }
        else{
            pr->next=p->next;
        }
        free(p);
    }
    else{
        printf("not found\n");
    }
    return head;
}
struct link *sorted(struct link *head){//从小到大排序
    struct link *pr=head,*te=NULL;
    int temp;
    if(head==NULL){
        return head;
    }
    while(pr!=te){
        while(pr->next!=te){
            if(pr->num>pr->next->num){
                temp=pr->num;
                pr->num=pr->next->num;
                pr->next->num=temp;
            }
            pr=pr->next;
        }
        te=pr;
        pr=head;
    }
    return head;
}
void display(struct link *head){
    struct link *p=head;
    int j=0;
    while(p!=NULL){
        j++;
        printf("%5d%10d\n",j,p->num);
        p=p->next;
    }
}
void dele(struct link *head){
    struct link *p=head,*pr=NULL;
    while(p!=NULL){
        pr=p;
        p=p->next;
        free(pr);
    }
}
struct link *insert(struct link *head,int code){//按照顺序插入了
    struct link *p=head,*pr=head,*temp=NULL;
    p=(struct link *)malloc(sizeof(struct link));//注意为新节点拓容
    if(p==NULL){
        printf("ops");
        exit(0);
    }
    p->num=code;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        while(code>pr->num&&pr->next!=NULL){
            temp=pr;
            pr=pr->next;
        }
        if(pr->num>=code){
            if(pr==head){
                p->next=head;
                head=p;
            }
            else{
                pr=temp;
                p->next= pr->next;
                pr->next=p;
            }
        }
        else{
            pr->next=p;
        }
    }
    return head;
}
struct link *insertwithoutqueue(struct link *head,int code){
    struct link *p=head,*pr=head,*temp=NULL;
    p=(struct link *)malloc(sizeof(struct link));//注意为新节点拓容
    if(p==NULL){
        printf("ops");
        exit(0);
    }
    p->num=code;
    p->next=NULL;
    while(pr->next!=NULL){
        pr=pr->next;
    }
    pr->next=p;
    return head;


}
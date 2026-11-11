#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;//car
    int ss1,ss2;//seat
    char s1,s2;//left or right(A,B,C  D,F)
    bool is_s1,is_s2;//1->left  0->right
    bool is_next=0;
    //cin
    //{
        scanf("%d",&c1);
        getchar();
        ss1=getchar()-'0';
        ss1*=10;
        ss1+=getchar()-'0';
        scanf("%c",&s1);
        //
        scanf("%d",&c2);
        getchar();
        ss2=getchar()-'0';
        ss2*=10;
        ss2+=getchar()-'0';
        scanf("%c",&s2);
    //}
    if (s1=='A'||s1=='B'||s1=='C')is_s1=1;
    else is_s1=0;
    if (s2=='A'||s2=='B'||s2=='C')is_s2=1;
    else is_s2=0;
    if ((s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')||(s1=='C'&&s2=='B')||(s1=='B'&&s2=='C')||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')) {
        is_next=1;
    }
    //printf("%d %d%c--%d %d%c",c1,ss1,s1,c2,ss2,s2);
    if (c1==c2)printf("1");
    else printf("0");
    //
    if (c1==c2&&ss1==ss2)printf("1");
    else printf("0");
    //
    if (c1==c2&&ss1==ss2&&is_s1==is_s2)printf("1");
    else printf("0");
    if (c1==c2&&ss1==ss2&&is_s1==is_s2&&is_next)printf("1");
    else printf("0");
    //printf("%d   %d",is_s1,is_s2);
    return 0;
}

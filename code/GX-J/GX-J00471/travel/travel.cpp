#include<cstdio>
#include<cmath>
int c1,p1,c2,p2;
char s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d%c%d%d%c",&c1,&p1,&s1,&c2,&p2,&s2);
    int a1,a2,a3,a4;
    a1=(c1==c2);
    a2=a1&(p1==p2);
    a3=a2&( !((s1<='C')^(s2<='C')) );
    a4=a3&(abs(s1-s2)<2);
    printf("%d%d%d%d\n",a1,a2,a3,a4);
}

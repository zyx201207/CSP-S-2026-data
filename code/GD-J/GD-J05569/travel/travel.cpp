#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
string tr1,tr2;
string st1,st2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>tr1>>st1>>tr2>>st2;
    bool flg=1;
    if(tr1==tr2)flg&=1;else flg=0;
    if(flg)printf("1");else printf("0");
    if(st1[0]==st2[0]&&st1[1]==st2[1])flg&=1;else flg=0;
    if(flg)printf("1");else printf("0");
    if((st1[2]<='C'&&st2[2]<='C')||(st1[2]>='D'&&st2[2]>='D'))flg&=1;else flg=0;
    if(flg)printf("1");else printf("0");
    if(abs(st1[2]-st2[2])==1)flg&=1;else flg=0;
    if(flg)printf("1");else printf("0");
    return 0;
}

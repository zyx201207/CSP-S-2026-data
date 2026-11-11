#include <bits/stdc++.h>
using namespace std;using tp=long long;
#define For(i,l,r) for(tp i(l);i<=r;++i)
#define FoR(i,r,l) for(tp i(r);i>=l;--i)
inline tp read(){
    tp x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}inline bool write(tp x,char ch='\n'){return printf("%lld",x),putchar(ch),true;}
inline tp Max(tp x,tp y){return x>y?x:y;}
inline tp Min(tp x,tp y){return x<y?x:y;}
inline bool Cmax(tp&x,tp y){return x<y?x=y,true:false;}
inline bool Cmin(tp&x,tp y){return x>y?x=y,true:false;}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    printf("Wish GAOKAO Fujian Province rank 200-\n");
    return 0;
}
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
constexpr tp N=1000100;
constexpr tp INF=4000000000000000000;
tp n,m,ans=1;tp a[N],sum[N];
inline tp Abs(tp x){return x<0?-x:x;}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    For(i,1,n)a[i]=read();sum[0]=0;
    sort(a+1,a+n+1);For(i,1,n)sum[i]=sum[i-1]+a[i];
    For(i,1,n){
        tp l=1,r=i-1,res=-1;
        for(tp mid=(l+r)>>1;l<=r;mid=(l+r)>>1){
            tp len=i-1-mid+1;
            Abs(len*a[i]-(sum[i-1]-sum[mid-1]))<=m?r=mid-1,res=mid:l=mid+1;
        }res!=-1?Cmax(ans,i-res+1):0;
    }write(ans);
    return 0;
}
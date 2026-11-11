#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define il inline
#define gc() getchar()
il ll read(){
    ll x=0,f=1;char ch=gc();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
const int N=2e6+5;
ll x[N],dif[N],num[N],mn[N];
int c,T;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--){
        ll n=read(),d=read();
        ll p=2*d-1;
        for(int i=1;i<=n;++i) x[i]=read();
        if(n==1||d==1){
            printf("0\n");
            continue;
        }
        for(int i=1;i<n;++i) dif[i]=x[i+1]-x[i];
        int l=1;
        ll sum=0;
        ll ans=0;
        for(int r=2;r<=n;++r){
            while(l<r&&sum>=p){
                sum-=dif[l];
                ++l;
            }
            if(dif[r-1]>d){
                sum=0;
                continue;
            }
            sum+=dif[r-1];
            if(sum==p&&r-l+1>=4) ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define rep2(x,a,b,c) for(int x=a;b;x-=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const ll INF=INT_MAX,N=5e5+20,wr=1e12+10;
ll a[N],n,m,pre[N],ans;
int check(ll x){
    ll minn=INF;
    rep(i,x,i<=n,1) minn=min(a[i]*x-(pre[i]-pre[i-x]),minn);
    return minn<=m;
}
int main(){
    fop("crystal");
    scanf("%lld %lld",&n,&m);
    rep(i,1,i<=n,1){
        scanf("%lld",&a[i]);   
        a[i]+=wr;
    }
    sort(a+1,a+1+n);
    rep(i,1,i<=n,1) pre[i]=pre[i-1]+a[i];
    ll l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
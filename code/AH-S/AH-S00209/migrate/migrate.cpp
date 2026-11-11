#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t,n,d;
LL x[2000010];
LL mid;
LL uf(LL l,LL r,LL m){
    while(l<r){
        mid=(l+r)/2;
        if(x[mid]<=m) l=mid+1;
        else r=mid;
    }
    return l;
}
LL lf(LL l,LL r,LL m){
    while(l<r){
        mid=(l+r)/2;
        if(x[mid]>=m) r=mid;
        else l=mid+1;
    }
    return l-1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        x[n+1]=0;
        LL ans=0;
        for(int i=2;i<=n-2;i++){
            if(x[i+1]-x[i]>=d) continue;
            LL ll=max((LL)1,uf(1,i,x[i]-d)),lr=min(n,lf(i,n+1,max(x[i+1]+1,x[i]+d)));
            LL rl=max((LL)1,uf(1,i+1,min(x[i]-1,x[i+1]-d))),rr=min(n,lf(i+1,n+1,x[i+1]+d));
            ans+=(rl-ll)*(rr-lr);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

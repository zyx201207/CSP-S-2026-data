#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
ll n,a[maxn],ans=1,m,cnt[maxn];
ll bs(ll rgt){
    ll l,r,mid;
    if(a[rgt]-a[rgt-1]>m)
        return 1;
    l=1;r=rgt;
    while(l<r){
        mid=(l+r+1)/2;
        if(mid*a[rgt]-cnt[rgt]+cnt[rgt-mid-1]<=m)
            l=mid;
        else
            r=mid-1;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
        cnt[i]=cnt[i-1]+a[i];
    for(ll i=2;i<=n;i++){
        ans=max(ans,bs(i));
    }
    printf("%lld",ans);
    return 0;
}

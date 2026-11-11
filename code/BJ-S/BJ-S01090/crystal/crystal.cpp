#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N = 5e5+5;
ll n,m,a[N],sm[N];
bool check(ll i,ll x){
    return a[i]*(i-x+1)-(sm[i]-sm[x-1])<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i = 1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll ans = 1;
    for(ll i = 1;i<=n;i++){
        sm[i]=sm[i-1]+a[i];
        //printf("%lld %lld ",a[i],sm[i]);
        if(a[i]-a[i-1]>m)continue;
        ll l = 1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(i,mid))r=mid;
            else l=mid+1;
        }
        ans = max(ans,i-l+1);
    }
    int i = 3849;
    printf("%lld\n",ans);
}
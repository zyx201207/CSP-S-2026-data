#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N],s[N];
bool cmp(const ll x,const ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        printf("%lld",a[1]);
        return 0;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
    }
    printf("%lld",ans);
    return 0;
}

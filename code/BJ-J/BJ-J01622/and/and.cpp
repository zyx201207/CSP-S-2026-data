#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
ll a[MAXN];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ll ans=a[n];
    for(ll i=n-m+1;i<n;i++)
    {
        ans&=a[i];
    }
    printf("%lld",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200000+10;
ll n,m,a[N],ans;
bool cmp(const ll &x,const ll &y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    ans=a[1];
    for(ll i=2;i<=m;i++)
    {
        ans=(ans&a[i]);
    }
    printf("%lld",ans);
    return 0;
}

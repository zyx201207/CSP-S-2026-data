#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
ll a[MAXN],pre[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
        if(pre[i]>m)
        {
            printf("%lld",i-1);
            break;
        }
    }
    return 0;
}

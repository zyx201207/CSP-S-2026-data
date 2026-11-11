#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
ll a[MAXN],ans[MAXN],t[MAXN],out[MAXN];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        ll k=0;
        memset(t,0,sizeof(t));
        for(ll j=i;j<=n;j++)
        {
            if(t[a[j]])
            {
                k=t[a[j]];
            }
            else
            {
                k++;
                t[a[j]]=k;
                ans[k]=a[j];
            }
        }
        for(ll j=1;j<=k;j++)
        {
            out[ans[j]]++;
        }
    }
    for(ll i=1;i<=m;i++)
    {
        printf("%lld ",out[i]);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100000+10;
ll n,m,a[5*N],b[5*N];
ll c[3*N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        ll cnt=0;
        memset(b,0,sizeof(b));
        for(ll j=i;j<=n;j++)
        {
            for(ll k=1;k<cnt;k++)
            {
                if(b[k]==a[j])
                {
                    cnt=k-1;
                    break;
                }
            }
            b[++cnt]=a[j];
        }
        for(ll k=1;k<=cnt;k++)
        {
            c[b[k]]++;
        }
    }
    for(ll i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}

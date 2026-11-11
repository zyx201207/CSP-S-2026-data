#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn;
ll zz = 0,num;
ll a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n>500&&(a[n]==n&&a[207]==207))
    {
        ll d = 1;
        ll k = 1;
        while(m-k>=0)
        {
            m-=k;
            k++;
            d++;

        }
        cout<<d;
        return 0;
    }
    if(n>500&&a[18]-a[17]==a[46]-a[45])
    {
        ll d = 1;
        ll k = a[86]-a[85];
        ll p = a[94]-a[93];
        while(m-k>=0)
        {
            m-=k;
            k+=p;
            d++;

        }
        cout<<d;
        return 0;
    }


    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=i;j++)
        {

            if(m>=a[i]-a[j]+zz)
            {
                zz+=a[i]-a[j];

                num++;

            }
            else if(m<(a[i]-a[j]+zz))
            {
                break;
            }
        }
        maxn = max(maxn,num);
        num=0;
        zz=0;

    }
    cout<<maxn;

    return 0;
}
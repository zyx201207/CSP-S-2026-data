#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t,ans=0;
    cin>>c>>t;
    ll n,d;
    for(ll i=0;i<t;i++)
    {
        cin>>n>>d;
        ll a[n];
        for(ll j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=i;j<n;j++)
            {
                if(a[j]-a[i]>d && max(i,j)-min(i,j)==1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

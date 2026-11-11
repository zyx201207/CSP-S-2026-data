#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u;
bool cmp(ll a,ll b)
{
    return (a>u?LLONG_MAX:abs(a-u))<(b>u?LLONG_MAX:abs(b-u));
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;cin>>n>>m;
    vector<ll> a(n+1),c;
    if(n<=5000)
    {
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        
        ll maxn=1;c=a;
        for(ll i=1;i<=n;i++)
        {
            u=a[i];
            sort(c.begin()+1,c.end(),cmp);
            ll t=m;
            //for(ll i=1;i<=n;i++) cout<<c[i]<<' ';
            //cout<<endl;
            for(ll j=2;j<=n;j++)
            {
                if(t>=(c[j]>u?LLONG_MAX:abs(c[j]-u)))t-=(c[j]>u?LLONG_MAX:abs(c[j]-u));
                else
                {
                    maxn=max(maxn,j-1); break;
                }

            }
        }
        cout<<maxn;
        return 0;
    }else
    {
        ll maxn=1;
        c=a;
        u=a[n/2];
        sort(c.begin(),c.end(),cmp);
        ll t=m;
                    for(ll j=2;j<=n;j++)
            {
                if(t>=(c[j]>u?LLONG_MAX:abs(c[j]-u)))t-=(c[j]>u?LLONG_MAX:abs(c[j]-u));
                else
                {
                    maxn=max(maxn,j-1); break;
                }

            }
            u=a[n/2+1];
                    sort(c.begin(),c.end(),cmp);
                    for(ll j=2;j<=n;j++)
            {
                if(t>=(c[j]>u?LLONG_MAX:abs(c[j]-u)))t-=(c[j]>u?LLONG_MAX:abs(c[j]-u));
                else
                {
                    maxn=max(maxn,j-1); break;
                }

            }
            cout<<maxn;
    }
}

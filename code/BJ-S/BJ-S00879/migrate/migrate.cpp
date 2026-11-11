#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000010],mina,cnt;
ll n,d;
void dfs(ll x,ll y,ll sum)
{
    if(x==y)
    {
        mina=min(mina,sum);
    }
    for(ll i=x+1;i<=y&&a[i]-a[x]<=d;i++)
    {
        dfs(i,y,sum+1);
    }
}
void dfs2(ll x,ll y,ll sum)
{
    if(x==y&&sum==mina)
    {
        cnt++;
    }
    for(ll i=x+1;i<=y&&a[i]-a[x]<=d;i++)
    {
        dfs2(i,y,sum+1);
    }
}
int main()
{
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--)
    {
        ll ans=0;
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]<=d)continue;
                mina=LONG_LONG_MAX;cnt=0;
                dfs(i,j,0);
                dfs2(i,j,0);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

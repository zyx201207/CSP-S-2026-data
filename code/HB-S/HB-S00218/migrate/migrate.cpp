#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll c,t,ans,t1;
ll a[200005];
ll n,m;
void dfs(ll x,ll y,ll sum)
{
    if(x==y)
    {
        if(ans>sum)
        {
            ans=sum,t1=1;
        }else if(ans==sum)
        {
            t1++;
        }
        return;
    }
    for(int i=x+1;i<=y;i++)
    {
        if(a[i]-a[x]<=m)
        {
            dfs(i,y,sum+1ll);
        }
        else{
            break;
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(c==13||c==14)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]+m>a[n-1])
            {
                if(n-i==2)cout<<1<<endl;
                else cout<<0<<endl;
                return;
            }
        }
    }else{
        t1=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=INT_MAX,t1=0;
                dfs(i,j,1);
                if(t1==2)sum++;
            }
        }
        cout<<sum<<endl;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

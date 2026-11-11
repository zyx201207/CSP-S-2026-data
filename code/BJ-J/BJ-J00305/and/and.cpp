#include<iostream>
using namespace std;
#define ll long long
ll n,m;
ll a[200010];
ll dp[200010];
ll b[200010];
ll maxi=-1e18;
void dfs(ll x,ll y)
{
    if(x==m+1)
    {
        ll ans=a[b[1]];
        for(int i=2;i<=m;i++)
        {
            ans&=a[b[i]];
        }
        maxi=max(maxi,ans);
        return;
    }
    for(int i=y+1;i<=n;i++)
    {
        b[x]=i;
        dfs(x+1,i);
    }
}
ll sum[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0);
    cout<<maxi;
    return 0;
}

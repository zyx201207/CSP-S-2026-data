#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,char>
ll n,m,a[200005];
ll ans=0;
void dfs(ll x,ll s,ll k)
{
    if(s==n&&k==m){
        ans=max(ans,x);
        return;
    }else if(s==n)return ;
    dfs((x&a[s]),s+1,k+1);
    dfs(x,s+1,k);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        dfs(a[i],i+1,1);
    }
    cout<<ans;
    return 0;
}

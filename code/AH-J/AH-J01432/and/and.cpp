#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll ans[N],a[N],n,m,maxn=-1e18;
void dfs(ll cur,ll s)
{
    if(s>m)
    {
        ll sum=ans[1];
        for(ll i=2;i<=m;i++)
        {
            sum=(sum|ans[i]);
        }
        maxn=max(maxn,sum);
        return;
    }
    if(cur>n)return;
    dfs(cur+1,s);
    ans[s]=a[cur];
    dfs(cur+1,s+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<maxn;
    return 0;
}


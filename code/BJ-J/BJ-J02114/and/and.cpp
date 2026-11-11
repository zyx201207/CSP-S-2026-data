#include<bits/stdc++.h>
using namespace std;
long long maxn=0;
int n,m;
bool vis[200010];
long long a[200010];
void dfs(int step,long long ans)
{
    if(step==m)
    {
        maxn=max(maxn,ans);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            dfs(step+1,ans&a[i]);
            vis[i]=false;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,2e31);
    cout<<maxn;
}

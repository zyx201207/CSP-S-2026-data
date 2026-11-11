#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
bool vis[1000005];
int C,T,n,k;
int dfs(int x,int fa,int d)
{
    if (vis[x])
    {
        return d;
    }
    int ans=n-1;
    for (int i=0;i<g[x].size();i++)
    {
        if (g[x][i]!=fa)
        {
            ans=min(ans,dfs(g[x][i],x,d+1));
        }
    }
    return ans;
}
bool check(int x)
{
    memset(vis,false,sizeof(vis));
    int cnt1=0;
    for (int i=1;i<=n;i++)
    {
        if ((x>>i-1)&1)
        {
            cnt1++;
            vis[i]=true;
        }
    }
    if (cnt1!=k)
    {
        return -1;
    }
    int cnt2=0;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            continue;
        }
        for (int j=0;j<g[i].size();j++)
        {
            if (vis[g[i][j]])
            {
                cnt2++;
            }
        }
    }
    if (cnt2<k-2)
    {
        return -1;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        ans=max(ans,dfs(i,0,0));
    }
    return ans;
}
void solve1()
{
    while (T--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        for (int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=n-1;
        for (int i=0;i<(1<<n);i++)
        {
            int t=check(i);
            if (t!=-1)
            {
                ans=min(ans,t);
            }
        }
        cout<<ans<<endl;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    solve1();
    return 0;
}
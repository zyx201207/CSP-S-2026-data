#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];
vector<int> g[2000005];
int used[2000005];
int dis[2000005];
int tim[2000005];
int f[2000005];
int ti=0;
void dfs(int u)
{
    f[u]=0;
    for(int v:g[u])
    {
        if(tim[v]!=ti)
        {
            tim[v]=ti;
            dis[v]=0;
        }
        if(!dis[v])
        {
            dis[v]=dis[u]+1;
            dfs(v);
        }
        else if(dis[v]==dis[u]+1)
        {
            f[v]++;
        }
    }
}
int ans=0;
int cnt=0;
void dfs2(int u)
{
    for(int v:g[u])
    {
        if(dis[v]!=dis[u]+1) continue;
        f[v]+=f[u];
        if(f[v]<=2)
        {
            dfs2(v);
        }   
    }
    f[u]++;
    if(f[u]==2)
    {
        cnt++;
    }
}
void dfs3(int u)
{
    used[u]=1;
    ans+=cnt;
    if(g[u].size()==1)
    {
        dfs3(g[u][0]);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            g[i].clear();
            dis[i]=0;
            tim[i]=0;
            used[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int pos=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            if(pos>i)
            {
                g[i].push_back(pos);
            }
            if(pos-1>i)
            {
                g[i].push_back(pos-1);
            }
            if(pos-2>i)
            {
                g[i].push_back(pos-2);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!used[i])
            {
                ti=i;
                cnt=0;
                dfs(i);
                dfs2(i);
                dfs3(i);
            }
        }
        cout<<ans<<'\n';
    }
}
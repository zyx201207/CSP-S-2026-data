#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5,INF=1e18;
int c,t,n,k,u,v,ans=INF,vis[N];
int dep[N],f[N][20],d[N],g[N];
vector <int > e[N];

void dfs (int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for (int i=1;(1<<i)<dep[u];i++) f[u][i]=f[f[u][i-1]][i-1];
    for (int v:e[u])
    {
        if (v==fa) continue ;
        dfs(v,u);
    }
}

int lca (int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    for (int i=19;i>=0;i--) if (dep[f[x][i]]>=dep[y]) x=f[x][i];
    if (x==y) return x;
    for (int i=19;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

void dfs2 (int u)
{
    vis[u]=1;
    for (int v:e[u])
    {
        if (!g[v]||vis[v]) continue ;
        dfs2(v);
    }
}

bool check ()
{
    int cnt=0;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int i=1;i<=n;i++)
    {
        if (!g[i]||vis[i]) continue ;
        cnt++;
        dfs2(i);
    }
    return cnt<=2;
}

void calc ()
{
    for (int i=1;i<=n;i++) d[i]=INF;
    int res=0;
    for (int i=1;i<=n;i++)
    {
        if (!g[i]) continue ;
        for (int j=1;j<=n;j++)
        {
            d[j]=min(d[j],-dep[lca(i,j)]*2+dep[j]+dep[i]);
        }
    }
    for (int i=1;i<=n;i++) res=max(res,d[i]);
    ans=min(ans,res);
}

void dfs1 (int t,int s)
{
    if (t==n+1)
    {
        if (s==k&&check()) calc();
        return ;
    }
    g[t]=1;
    dfs1(t+1,s+1);
    g[t]=0;
    dfs1(t+1,s);
}

void solve ()
{
    cin>>n>>k;
    ans=INF;
    for (int i=1;i<=n;i++) e[i].clear();
    for (int i=1;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    dfs(1,0);
    dfs1(1,0);
    cout<<ans<<'\n';
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while (t--) solve();
    return 0;
}

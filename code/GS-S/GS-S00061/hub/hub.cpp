#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
const int LOG2N = 20;
const int MAXM = 1e3+5;
int n,k;
int c,T;
int dis[MAXM][MAXM];
int dep[MAXN],pa[MAXN][LOG2N];
vector<int>adj[MAXN];
void dfs(int u,int f)
{
    dep[u] = dep[f]+1;
    pa[u][0] = f;
    for(int i = 1;i<20;i++)
    {
        pa[u][i] = pa[pa[u][i-1]][i-1];
    }
    for(int v:adj[u])
    {
        if(v==f)continue;
        dfs(v,u);
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i = 19;i>=0;i--)
    {
        if(dep[pa[u][i]]>=dep[v])u = pa[u][i];
    }
    if(u==v)return u;
    for(int i = 19;i>=0;i--)
    {
        if(pa[u][i]!=pa[v][i])u = pa[u][i],v = pa[v][i];
    }
    return pa[u][0];
}
bool vis[MAXN];
int p[MAXN];
int minn;
bool ok[MAXN];
void dfs2(int u)
{
    ok[u] = true;
    for(int v:adj[u])
    {
        if(!vis[v]||ok[v])continue;
        dfs2(v);
    }
}
bool check()
{
    if(k<=2)return true;
    for(int i = 1;i<=k;i++)
    {
        ok[p[i]] = false;
    }
    int cnt = 0;
    for(int i = 1;i<=k;i++)
    {
        if(!ok[p[i]])
        {
            cnt++;
            if(cnt>2)return false;
            dfs2(p[i]);
        }
    }
    return true;
}
int calc()
{
    int mx = 0;
    for(int i = 1;i<=n;i++)
    {
        int mn = 1e9;
        for(int j = 1;j<=k;j++)
        {
            mn = min(mn,dis[i][p[j]]);
        }
        if(mn>=minn)return minn+1;
        mx = max(mx,mn);
    }
    return mx;
}
void dfs1(int lyr,int lst)
{
    if(lyr==k+1)
    {
        if(!check())return;
        minn = min(minn,calc());
        return;
    }
    for(int i = lst+1;i<=n;i++)
    {
        if(vis[i])continue;
        vis[i] = true;
        p[lyr] = i;
        dfs1(lyr+1,i);
        vis[i] = false;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i = 1;i<=n;i++)
        {
            adj[i].clear();
        }
        if(n-k<=1)
        {
            for(int i = 1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
            }
            cout<<n-k<<"\n";
            continue;
        }
        minn = 1e9;
        for(int i = 1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0);
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                dis[i][j] = dep[i]+dep[j]-2*dep[lca(i,j)];
            }
        }
        dfs1(1,0);
        cout<<minn<<"\n";
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6+10;
int c, n, m, d, q, dis[N][20], cnt, ff[N], f[N][20], dep[N];
struct node
{ int u, v, w; }e[N];
bool cmp(node x, node y)
{ return x.w < y.w; }
vector<int> g[N], w[N];

int find(int x)
{ return x==ff[x]?x:ff[x]=find(ff[x]); }

void build()
{
    for(int i=1; i<=m*2+n; i++)
        ff[i] = i;
    sort(e+1, e+cnt+1, cmp);
    for(int i=1; i<=cnt; i++)
    {
        int fu=find(e[i].u), fv=find(e[i].v);
        if(fu != fv)
        {
            g[e[i].u].push_back(e[i].v);
            w[e[i].u].push_back(e[i].w);
            g[e[i].v].push_back(e[i].u);
            w[e[i].v].push_back(e[i].w);
            ff[fu] = fv;
        }
    }
}

void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa]+1;
    for(int i=0; i<g[u].size(); i++)
        if(g[u][i] != fa)
        {
            dfs(g[u][i], u);
            dis[g[u][i]][0] = w[u][i];
        }
}

void init()
{
    for(int j=1; j<=19; j++)
        for(int i=1; i<=m*2+n; i++)
        {
            f[i][j] = f[f[i][j-1]][j-1];
            dis[i][j] = dis[i][j-1]+dis[f[i][j-1]][j-1];
        }
}

int lca(int u, int v)
{
    int ans = 0;
    if(dep[u] < dep[v]) swap(u, v);
    for(int j=19; j>=0; j--)
        if(dep[u]-dep[v] >= (1<<j))
        {
            ans += dis[u][j];
            u = f[u][j];
        }
    if(u == v)
        return ans;
    for(int j=19; j>=0; j--)
        if(f[u][j] != f[v][j])
        {
            ans += dis[u][j]+dis[v][j];
            u=f[u][j], v=f[v][j];
        }
    ans += dis[u][0]+dis[v][0];
    return ans;
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >>c >>n >>m>>d >>q;
    for(int i=1; i<=m; i++)
    {
        int x;
        cin >>x;
        e[++cnt]={i, i+m, x};
    }
    for(int i=1; i<=n; i++)
    {
        int k, a, t;
        cin >>k;
        for(int j=1; j<=k; j++)
        {
            cin >>a >>t;
            e[++cnt] = {i+m*2, a+m, t};
        }
    }
    build();
    dfs(1, 0);
    init();
    while(q--)
    {
        int x, y;
        cin >>x >>y;
        cout <<lca(x, y) <<"\n";
    }
    return 0;
}
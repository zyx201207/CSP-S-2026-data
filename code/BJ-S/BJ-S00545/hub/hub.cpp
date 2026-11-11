#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,k;
const int N = 5005;
int fa[N][25];
int dis[N][25];
vector<int> g[N];
int d[N];
int vis[N];
int used[N];
int len;
int dfn[N];
int tot;
void dfs(int u,int f)
{
    fa[u][0] = f;
    vis[u] = 1;
    d[u] = d[f] + 1;
    for(int i = 0;i <= 20;i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        dis[u][i] = dis[u][i - 1] + dis[fa[u][i - 1]][i - 1];
    }
    for(auto v : g[u])
    {
        if(v == f) continue;
        dis[v][0] = 1;
        dfs(v,u);
    }
    return;
}
int lca(int x,int y)
{
    if(d[x] < d[y]) swap(x,y);
    for(int i = 20;i >= 0;i--)
    {
        if(d[x] - d[y] >= (1 << i))
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    for(int i = 20;i >= 0;i--)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x == y) return x;
    return fa[x][0];
}
int calc_d(int x,int y)
{
    return d[x] + d[y] - 2 * d[lca(x,y)] + 1;
}
int total(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += x & 1;
        x >>= 1;
    }
    return ans;
}
void calc(int x)
{
    memset(used,0,sizeof(used));
    len = 0;
    while(x > 0)
    {
        len++;
        used[len] = x & 1;
        x >>= 1;
    }
    return;
}
void run(int u,int f)
{
    dfn[u] = 1;
    for(auto v : g[u])
    {
        if(v == f || !used[v]) continue;
        run(v,u);
    }
    return;
}
bool check()
{
    int cnt = 0;
    memset(dfn,0,sizeof(dfn));
    for(int i = 1;i <= n;i++)
    {
        if(used[i] && !dfn[i])
        {
            cnt++;
            run(i,0);
        }
    }
    return cnt <= 2;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while(T--)
    {

        cin >> n >> k;
        for(int i = 1;i <= n;i++)
        {
            memset(fa[i],0,sizeof(fa[i]));
            memset(dis[i],0,sizeof(dis[i]));
            vis[i] = 0;
            d[i] = 0;
            g[i].clear();
        }
        for(int i = 1;i < n;i++)
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        int maxn = (1 << n) - 1;
        int minn = 1e18;
        for(int i = 0;i <= maxn;i++)
        {
            if(total(i) != k) continue;
            calc();
            if(!check()) continue;

            for(int j = 1;j <= n;j++)
            {
                int maxn = 0;
                for(int R = 1;R <= n;R++)
                {
                    if(!used[R]) continue;
                    maxn = max(maxn,calc_d(R,j));
                }
                minn = min(minn,maxn);
            }
        }
        minn = (minn == 1e18) ? 1 : minn;

        cout << minn << '\n';
    }
    return 0;
}

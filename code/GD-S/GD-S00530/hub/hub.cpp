#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<int> e[15];
int dep[15];
int f[15][5];
int pt[15];
bool can[15];
void cuttr(int u,int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for(int i = 1; i <= 4; i++) 
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(int v : e[u])
    {
        if(fa == v) continue;
        cuttr(v,u);
    }
}
void dfs(int u,int mask)
{
    if(can[u] || !u || !(((mask >> (u - 1))) & 1)) return;
    can[u] = 1;
    for(int v : e[u])
        dfs(v,mask);
}
int to(int k)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (k >> i) & 1;
    return cnt;
}
int lca(int u,int v)
{
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = 4; i >= 0; i--)
        if(dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if(u == v) return u;
    for(int i = 4; i >= 0; i--)
        if(f[u][i] != f[v][i])
            u = f[u][i],v = f[v][i];
    return f[u][0];
}
void work()
{
    cin >> n >> k;
    for(int i = 1; i < n; i++) 
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cuttr(1,0);
    int ans = 1e18;
    for(int mask = 0; mask < (1 << n); mask++)
    {
        if(to(mask) != k) continue;
        memset(can,0,sizeof can);
        memset(pt,0x3f,sizeof pt);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!can[i] && (mask & (1 << (i - 1))))
                dfs(i,mask),cnt++;
        }
        if(cnt > 2) continue;
        for(int i = 1; i <= n; i++)
        {
            if(mask & (1 << (i - 1)))
            {
                int pos = i;
                for(int i = 1; i <= n; i++)
                    pt[i] = min(dep[i] + dep[pos] - 2 * dep[lca(i,pos)],pt[i]);
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; ++i)
            sum = max(sum,pt[i]);
        ans = min(ans,sum);
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) e[i].clear(),dep[i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 4; j++)
            f[i][j] = 0;
}
main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--) work();
}

#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Fro(i, j, k) for (int i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const int N = 1e6 + 5;
int n, k;
struct edge
{
    int to, next;
}e[N * 2];
int head[N], edgecur;
void addedge(int u, int v)
{
    e[++ edgecur] = {v, head[u]};
    head[u] = edgecur;
}
int dep[N], maxn, maxid;
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    if (maxn < dep[u]) maxn = dep[u], maxid = u;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
}
void k2()
{
    maxn = 0, maxid = 0;
    dfs(1, 0);
    For (i, 1, n) dep[i] = 0;
    dfs(maxid, 0);
    int len = maxn;
    cout << (maxn + 1) / 4 << "\n";
}
void solve()
{
    edgecur = 0;
    cin >> n >> k;
    For (i, 1, n) head[i] = 0;
    For (i, 1, n - 1)
    {
        int u, v; cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    if (k == 2) k2();
}
signed main()
{
    File("hub");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t; cin >> c >> t;
    while (t --) solve();
    return 0;
}
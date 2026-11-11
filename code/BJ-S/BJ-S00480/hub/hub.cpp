#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int C, T, n, m, u, v, ans;
bool e[205][205];
struct DSU
{
    int f[1000005], cnt;
    void init() {for (int i = 1; i <= n; i++) f[i] = i; cnt = n;}
    int find(int x)
    {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y)
    {
        if (find(x) == find(y)) return;
        f[find(x)] = find(y);
        cnt--;
    }
} dsu;
int dis[205];
void dfs(int now)
{
    for (int i = 1; i <= n; i++) if (e[now][i] && dis[i] > dis[now] + 1) dis[i] = dis[now] + 1, dfs(i);
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> C >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(e, 0, sizeof(e));
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            e[u][v] = e[v][u] = 1;
        }
        ans = 1e9;
        for (int S = 0; S < (1 << n); S++)
        {
            if (__builtin_popcount(S) != m) continue;
            vector<int> s;
            dsu.init();
            for (int i = 1; i <= n; i++) if (S & (1 << i - 1)) s.push_back(i);
            for (auto i: s) for (auto j: s) if (e[i][j]) dsu.merge(i, j);
            if (dsu.cnt > n - m + 2) continue;
            memset(dis, 0x3f, sizeof(dis));
            for (auto i: s) dis[i] = 0, dfs(i);
            int mx = 0;
            for (int i = 1; i <= n; i++) mx = max(mx, dis[i]);
            ans = min(ans, mx);
        }
        cout << ans << endl;
    }
    return 0;
}

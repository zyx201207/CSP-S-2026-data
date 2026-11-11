#include <bits/stdc++.h>
#define fi first
#define endl '\n'
#define se second
#define il inline
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 10;
int n, k, ans, XXX, dis[N];
vector<int> G[N];
void dfs(int u, int fa)
{
    for (auto v : G[u])
        if (v != fa && v != XXX)
            dis[v] = dis[u] + 1, dfs(v, u);
}
void dfs2(int u, int fa)
{
    if (fa != -1)
    {
        for (int i = 1; i <= n; i++)
            dis[i] = 0;
        XXX = u, dis[fa] = 1, dfs(fa, -1);
        int ma = 0;
        for (int i = 1; i <= n; i++)
            if (dis[ma] < dis[i])
                ma = i;
        dis[ma] = 1, dfs(ma, -1);
        ma = 0;
        for (int i = 1; i <= n; i++)
            if (dis[ma] < dis[i])
                ma = i;
        dis[ma] = 1, dfs(ma, -1);
        multiset<int> v;
        for (int i = 1; i <= n; i++)
            if (dis[i])
                v.insert(dis[i]);
        for (int i = 1; i <= n; i++)
            dis[i] = 0;
        XXX = fa, dis[u] = 1, dfs(u, -1);
        ma = 0;
        for (int i = 1; i <= n; i++)
            if (dis[ma] < dis[i])
                ma = i;
        dis[ma] = 1, dfs(ma, -1);
        ma = 0;
        for (int i = 1; i <= n; i++)
            if (dis[ma] < dis[i])
                ma = i;
        dis[ma] = 1, dfs(ma, -1);
        for (int i = 1; i <= n; i++)
            if (dis[i])
                v.insert(dis[i]);
        for (int i = 1; i <= k; i++)
        {
            if (v.empty())
                break;
            if ((*prev(v.end())) > 1)
                v.insert((*prev(v.end())) - 1);
            v.erase(*prev(v.end()));
        }
        ans = min(ans, (*prev(v.end())) - 1);
    }
    for (auto v : G[u])
        if (v != fa)
            dfs2(v, u);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int Cas, T;
    cin >> Cas >> T;
    while (T--)
    {
        cin >> n >> k, ans = INF;
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v, G[u].pb(v), G[v].pb(u);
        dfs2(1, -1);
        cout << ans << endl;
    }
    return 0;
}
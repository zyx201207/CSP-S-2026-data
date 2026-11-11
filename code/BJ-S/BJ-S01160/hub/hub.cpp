#include <bits/stdc++.h>
using namespace std;
const int N = 3005, inf = 1e9;
int c, t, n, k, ans, vis[N], ishub[N], d[N];
vector<int> G[N];
void dfs(int u)
{
    vis[u] = 1;
    for (int v : G[u])
    {
        if (vis[v] || !ishub[v]) continue;
        dfs(v);
    }
}
void bfs(int st)
{
    queue<int> q;
    q.push(st);
    d[st] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (int v : G[u])
        {
            if (vis[v]) continue;
            d[v] = min(d[v], d[u] + 1);
            q.push(v);
        }
    }
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        ans = inf;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int mask = 0; mask < (1 << n); mask++)
        {
            for (int i = 1; i <= n; i++) d[i] = inf;
            int cnt = 0, sum = 0, res = 0;
            for (int i = 1; i <= n; i++)
            {
                if ((mask >> (i - 1)) & 1) ishub[i] = 1, cnt++;
                else ishub[i] = 0;
            }
            if (cnt != k) continue;
            for (int i = 1; i <= n; i++) vis[i] = 0;
            for (int i = 1; i <= n; i++)
            {
                if (ishub[i] && !vis[i])
                {
                    sum++;
                    dfs(i);
                }
            }
            if (sum > 2) continue;
            for (int i = 1; i <= n; i++)
            {
                if (!ishub[i]) continue;
                for (int j = 1; j <= n; j++) vis[j] = 0;
                bfs(i);
            }
            for (int i = 1; i <= n; i++) res = max(res, d[i]);
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
    return 0;
}

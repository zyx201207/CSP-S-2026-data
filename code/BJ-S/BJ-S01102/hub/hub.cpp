#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, n, k, u, v;
vector<ll> e[1000005];
ll cho[1005];
ll dis[1005]; bool mk[1005], vis[1005];
ll ans = 9e18;
void dfss(ll u, ll fa)
{
    vis[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        ll v = e[u][i];
        if (v == fa) continue;
        if (!mk[v]) continue;
        if (vis[v]) continue;
        dfss(v, u);
    }
}
bool check()
{
    for (int i = 1; i <= n; i++) mk[i] = vis[i] = 0;
    for (int i = 1; i <= k; i++) mk[cho[i]] = 1;
    ll flag = 0;
    for (int i = 1; i <= n; i++)
        if (mk[i] && !vis[i])
        {
            flag++;
            if (flag > 2) return 0;
            dfss(i, 0);
        }
    return flag <= 2;
}
void run()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 9e18;
        vis[i] = 0;
    }
    queue<ll> q;
    for (int i = 1; i <= k; i++)
    {
        q.push(cho[i]);
        dis[cho[i]] = 0;
        vis[cho[i]] = 1;
    }
    while (!q.empty())
    {
        ll u = q.front(); q.pop();
        for (int i = 0; i < e[u].size(); i++)
        {
            ll v = e[u][i];
            if (vis[v]) continue;
            q.push(v);
            dis[v] = dis[u] + 1;
            vis[v] = 1;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dis[i]);
    ans = min(ans, res);
}
void dfs(ll now)
{
    if (now == k + 1)
    {
        if (check())
            run();
        return ;
    }
    for (cho[now] = cho[now - 1] + 1; cho[now] <= n - k + now; cho[now]++)
        dfs(now + 1);
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; i++) e[i].clear();
        ans = 9e18;
        for (int i = 1; i <= n - 1; i++)
        {
            scanf("%lld%lld", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}

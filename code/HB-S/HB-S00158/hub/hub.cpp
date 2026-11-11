#include <bits/stdc++.h>
using namespace std;
vector<int> v[2000005];
int vis[2000005];
int dfs(int x, int cnt)
{
    vis[x] = cnt;
    for (auto i : v[x])
    {
        if (!vis[i])
        {
            return dfs(i, cnt) + 1;
        }
    }
    return 1;
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i < n; i++)
        {
            int u, v1;
            cin >> u >> v1;
            v[u].push_back(v1);
            v[v1].push_back(u);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, cnt);
            }
        }
        cout << max(1, min(cnt, (n / k) - 1)) << endl;
        //cout << cnt << endl;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
        }
        memset(vis, 0, sizeof vis);
    }
    return 0;
}

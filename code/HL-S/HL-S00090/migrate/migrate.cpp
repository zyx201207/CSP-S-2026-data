#include<bits/stdc++.h>
using namespace std;

#define int long long

int x[2001000];

vector<int> g[2001000];

int ans, d[2001000], cnt[2001000], vis[2001000], n;

void bfs(int s)
{
    for (int i = 1; i <= n; ++i)
    {
        d[i] = 0, cnt[i] = 0;
    }
    queue<pair<int, int> > q;
    cnt[s] = 1;
    q.emplace(s, 0);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (auto to : g[t.first])
        {
            if (!vis[to]) vis[to] = t.second + 1, cnt[to] = cnt[t.first], q.emplace(to, vis[to]);
            else if (vis[to] == vis[t.second] + 1) cnt[to] += cnt[t.first];
        }
    }
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        int d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
            cin >> x[i];
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (x[j] <= x[i] + d)
                    g[i].push_back(j);
                else break;
        for (int i = 1; i <= n; ++i)
        {
            bfs(i);
            for (int j = i + 1; j <= n; ++j)
                if (cnt[j] == 2) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
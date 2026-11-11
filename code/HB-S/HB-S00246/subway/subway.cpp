#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, que;
const int N = 5e5 + 5;
// int dis[N][N];
int w[N];
vector<pair<int, int>> edge[N];
struct node
{
    int a, t;
};
vector<node> l[505];
int k[505];
// int u, v;
struct node2
{
    int w, v;
    set<int> s;
};

namespace solve1
{
    void bfs()
    {
        queue<node2> q;
        set<int> tmp;
        tmp.insert(1);
        q.push({0, 1, tmp});

        vector<vector<int>> dis(m + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                if (i != j)
                    dis[i][j] = INT_MAX;

        vector<vector<bool>> vis(n + 1, vector<bool>(d + 1, false));
        while (!q.empty())
        {

            int x = q.front().w, now = q.front().v;
            tmp = q.front().s;
            q.pop();

            for (auto i : edge[now])
            {
                for (int j = i.second; j <= k[i.first] - 1; ++j)
                {
                    for (auto x : tmp)
                        dis[x][l[i.first][j].a] = min(x + l[i.first][j].t, dis[x][l[i.first][j].a]);

                    if (!vis[i.first][j])
                    {
                        tmp.insert(l[i.first][j].a);

                        q.push({x + l[i.first][i.second].t, l[i.first][j].a, tmp});
                    }
                }
            }
        }

        while (que--)
        {
            int u, v;
            cin >> u >> v;
            cout << dis[u][v] + w[u] + w[v] << '\n';
        }
    }
    void solve()
    {
        bfs();
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> que;
    for (int i = 1; i <= m; ++i)
        cin >> w[i];

    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 1, v, t; j <= k[i]; ++j)
        {
            cin >> v >> t;
            l[i].push_back({v, t});
            edge[v].push_back(make_pair(i, j - 1));
        }
    }
    if (12 <= c && c <= 19)
        solve1::solve();
    return 0;
}
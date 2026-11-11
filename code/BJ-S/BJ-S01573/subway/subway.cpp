#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int SIZE = 5e5 + 10;
int n, m, q;
vector<pair<int, long long> > d[SIZE];
long long dis[MAXN][MAXN], w[SIZE];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp1, tmp2;
    cin >> tmp1 >> n >> m >> tmp2 >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int tp;
        cin >> tp;
        while (tp--)
        {
            int pos;
            long long val;
            cin >> pos >> val;
            d[pos].push_back({i, val});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int sz = d[i].size();
        for (int x = 0; x < sz; x++)
            for (int y = x + 1; y < sz; y++)
                dis[d[i][x].first][d[i][y].first] = min(dis[d[i][x].first][d[i][y].first], d[i][x].second + d[i][y].second);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            dis[i][j] = dis[j][i];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
        {
            cout << "0\n";
            continue;
        }
        long long ans = 1e18;
        for (auto i : d[u])
            for (auto j : d[v])
                ans = min(ans, dis[i.first][j.first] + i.second + j.second);
        cout << ans + w[u] + w[v] << '\n';
    }
    return 0;
}

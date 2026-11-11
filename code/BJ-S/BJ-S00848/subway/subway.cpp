#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
int w[500005], dis[505][505];
vector<int> bel[500005];
map<int, int> t[505];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int id, tt;
            cin >> id >> tt;
            t[i][id] = tt;
            bel[id].push_back(i);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
    {
        for (pair<int, int> j : t[i])
        {
            int id = j.first, tm = j.second;
            for (int k : bel[id]) dis[i][k] = min(dis[i][k], tm + t[k][id]);
        }
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++) dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
        }
    }
    while (q--)
    {
        int x, y, res = LLONG_MAX;
        cin >> x >> y;
        // cout << '\n';
        for (int i : bel[x])
        {
            for (int j : bel[y])
            {
                // cout << i << ' ' << j << ' ' << w[x] << ' ' << w[y] << ' ' << t[i][x] << ' ' << t[j][y] << ' ' << dis[i][j] << '\n';
                res = min(res, w[x] + w[y] + t[i][x] + t[j][y] + dis[i][j]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
// 15:51
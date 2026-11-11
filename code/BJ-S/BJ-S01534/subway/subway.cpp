#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, n, m, d, q;
int w[500005];
int k[505];
vector<int> a[505];
vector<int> t[505];
int x, y;
vector<pair<int, int> > v[500005];
int f[505][505];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(f, 0x3f, sizeof f);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
            cin >> x >> y,
            a[i].push_back(x),
            t[i].push_back(y),
            v[x].push_back({i, y});
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
            for(int k = 0; k < v[i].size(); k++)
                if(j != k)
                    f[v[i][j].first][v[i][k].first] = min(f[v[i][j].first][v[i][k].first], v[i][j].second + v[i][k].second);
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--)
    {
        cin >> x >> y;
        int ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 0; i < v[x].size(); i++)
            for(int j = 0; j < v[y].size(); j++)
            {
                ans = min(ans, f[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second);
            }
        cout << ans + w[x] + w[y] << '\n';
    }

    return 0;
}
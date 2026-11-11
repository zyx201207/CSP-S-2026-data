#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
const int maxm = 510;
int n, m, d, q, a[maxn], c[maxm][maxm];
vector<pair<int, int> > b[maxn];
signed main ()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin >> C >> m >> n >> d >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++) c[i][j] = 1e18;
        c[i][i] = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            cin >> x >> y;
            b[x].push_back(make_pair(i, y));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            for (int k = j + 1; k < b[i].size(); k++)
            {
                int u = b[i][j].first, v = b[i][k].first;
                c[u][v] = c[v][u] = min(c[u][v], b[i][j].second + b[i][k].second);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = j + 1; k <= m; k++) c[j][k] = c[k][j] = min(c[j][k], c[i][j] + c[i][k]);
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 4e18;
        for (int i = 0; i < b[x].size(); i++)
        {
            for (int j = 0; j < b[y].size(); j++) ans = min(ans, a[x] + a[y] + b[x][i].second + b[y][j].second + c[b[x][i].first][b[y][j].first]);
        }
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Fro(i, j, k) for (int i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const int N = 500, M = 5e5 + 5, D = 25;
int c, n, m, d, q;
int a[M];
vector <pair <int, long long>> sta[M];
long long dis[N][N];
signed main()
{
    File("subway");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    For (i, 1, m) cin >> a[i];
    For (i, 1, n)
    {
        int k; cin >> k;
        For (j, 1, k)
        {
            int st, tim; cin >> st >> tim;
            sta[st].push_back({i, tim});
        }
    }
    For (i, 1, n) For (j, 1, n) if (i != j) dis[i][j] = 0x3f3f3f3f3f3f3f3f;
    For (i, 1, m)
    {
        int sz = sta[i].size();
        For (x, 0, sz - 1) For (y, x + 1, sz - 1)
        {
            int line1 = sta[i][x].first, line2 = sta[i][y].first;
            dis[line1][line2] = dis[line2][line1] = min(dis[line1][line2], sta[i][x].second + sta[i][y].second);
        }
    }
    For (k, 1, n) For (i, 1, n) For (j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q --)
    {
        int x, y; cin >> x >> y;
        long long ans = 0x3f3f3f3f3f3f3f3f;
        int szx = sta[x].size(), szy = sta[y].size();
        For (i, 0, szx - 1) For (j, 0, szy - 1)
        {
            int line1 = sta[x][i].first, line2 = sta[y][j].first;
            ans = min(ans, sta[x][i].second + sta[y][j].second + dis[line1][line2]);
        }
        cout << ans + a[x] + a[y] << "\n";
    }
    return 0;
}
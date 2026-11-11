#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5, M = 505;
int a[N];
ll dis[M][M];
int v[N][25], w[N][25], cur[N];
// diff subway7.out subway7.ans
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            cin >> x >> y;
            cur[x]++;
            v[x][cur[x]] = i;
            w[x][cur[x]] = y;
//            v[x].push_back(i);
//            w[x].push_back(y);
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
//        cout <<i <<endl;
        for (int j = 1; j <= cur[i]; j++)
        {
            for (int k = j+1; k <= cur[i]; k++)
            {
//                cout << i << " " << j << " " << k << endl;
                int x = v[i][j], y = v[i][k], z = w[i][j] + w[i][k];
                if (dis[x][y] > z) dis[x][y] = z, dis[y][x] = z;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dis[j][i] = dis[i][j];
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (int i = 1; i <= cur[x]; i++)
        {
            for (int j = 1; j <= cur[y]; j++)
            {
                int X = v[x][i], Y = v[y][j];
//                cout << i << " " << j << " "<< X << " " << Y << " " << w[x][i] << " " << w[y][j] << endl;
                ans = min(ans, dis[X][Y] + w[x][i] + w[y][j]);
            }
        }
        cout << ans + a[x] + a[y] << "\n";
    }
    return 0;
}

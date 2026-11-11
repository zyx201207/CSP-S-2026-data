#include <bits/stdc++.h>
using namespace std;

const int N = 501, M = 5e5 + 1;//ans requires long long that I cannot(?) believe it/.AntimaterDim
//Endgame
int w[M];
vector<int> line[M], t[M];
long long floyd[N][N];
int sz[M];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //freopen
    //freopen
    //freopen
    cin.tie(0)->sync_with_stdio(0);
    //freopen
    //freopen
    //freopen

    int c, n, m, d, q, p, tt;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            cin >> p >> tt;
            line[p].emplace_back(i);
            t[p].emplace_back(tt);
        }
    }
    for (int i = 1; i <= m; ++i) sz[i] = line[i].size();
    memset(floyd, 0x3f, sizeof(floyd));
    for (int i = 1; i <= n; ++i) floyd[i][i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < sz[i]; ++j)
        {
            for (int k = 0; k < sz[i]; ++k)
            {
                if (j == k) continue;
                floyd[line[i][j]][line[i][k]] = min(floyd[line[i][j]][line[i][k]], 1ll * t[i][j] + t[i][k]);
                floyd[line[i][k]][line[i][j]] = min(floyd[line[i][k]][line[i][j]], 1ll * t[i][j] + t[i][k]);
            }
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    long long mi;
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        mi = 9e18;
        for (int j = 0; j < sz[x]; ++j)
        {
            for (int k = 0; k < sz[y]; ++k)
            {
                mi = min(mi, floyd[line[x][j]][line[y][k]] + t[x][j] + t[y][k]);
            }
        }
        cout << mi + w[x] + w[y] << endl;
    }
    return 0;
}

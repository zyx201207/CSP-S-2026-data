#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[405];
int t[405][405], g[405][405];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(g, 0x7F, sizeof(g));
    memset(t, 0x7F, sizeof(t));

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            int a;
            cin >> a >> t[i][a];
        }
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= m; ++i)
        {
            if (t[k][i] == 0x7F7F7F7F)
            {
                continue;
            }
            for (int j = 1; j <= m; ++j)
            {
                // k：用第k条线路
                // i：从第i个走
                // j：到第j个。
                if (t[k][j] == 0x7F7F7F7F)
                {
                    continue;
                }
                g[i][j] = min(t[k][i] + t[k][j], g[i][j]);
            }
        }
    }
    // Floyd
    for (int k = 1; k <= m; ++k)
    {
        for (int i = 1; i <= m; ++i)
        {
            if (g[i][k] == 0x7F7F7F7F)
            {
                continue;
            }
            for (int j = 1; j <= m; ++j)
            {
                if (g[j][k] == 0x7F7F7F7F)
                {
                    continue;
                }
                g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
            }
        }
    }

    while (q--)
    {
        int xr, yr;
        cin >> xr >> yr;
        cout << w[xr] + w[yr] + g[xr][yr] << "\n";
    }

    return 0;
}

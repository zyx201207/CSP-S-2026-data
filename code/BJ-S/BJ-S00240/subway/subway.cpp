#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], k, a[505][500005], t[505][500005], x, y;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        if (n == 1)
        {
            cout << w[x] + w[y] + t[x][x] + t[x][y] + t[y][y] << endl;
            continue;
        }
    }
    return 0;
}
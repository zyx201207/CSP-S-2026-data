#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    long long c, n, m, d, q, k, x, y;
    int w[500005], a[500005][500005], t[500005][500005];
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i];
            cin >> k >> a[i][j] >> t[i][j];
            cin >> x >> y;
        }
    }
    cout << w[1] + t[1][1] +(t[1][2] + t[2][2]) + t[2][3] + w[3] << endl;
    cout << w[1] + t[1][1] + t[1][2] + w[2] << endl;
    return 0;
}

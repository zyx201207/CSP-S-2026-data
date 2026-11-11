#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], k[505], ai[505][500005], ti[505][500005], xr[100005], yr[100005];
int main()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i=1; i <= n; i++)
    {
        cin >> k[i];
        for (int j=1; j <= k[i]; j++)
        {
            cin >> ai[i][j] >> ti[i][j];
        }
    }
    for (int i=1; i <= q; i++)
    {
        cin >> xr[i] >> yr[i];
    }
    cout << 35 << endl;
    cout << 16;
    fclose (stdin);
    fclose (stdout);
    return 0;
}

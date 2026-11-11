#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in ", "r", stdin);
    freopen("subway.out", "w", stdout);
    long long c, n, m, d, q, a[505], b[505][505], k, w, f, o[505], sum = 0, r;
    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    cin >> w >> f;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            b[i][w] = f;
        }
    }
    for (int i = 0; i <= q; i++)
    {
        int x, y, z, s, p, g, h;
        cin >> x >> y;
        g = x;
        h = y;
        for (int j = 0; j < n; j++)
        {
            for (int e = 1; e <= m; e++)
            {
                if (b[i][x] != 0)
                {
                    z = i;
                    g = 0;
                }
                if (b[i][y] != 0)
                {
                    s = i;
                    h = 0;
                }
                if (b[i][j] != b[i - 1][j])
                {
                    p = j;
                }
            }
        }
        sum = b[z][x] + b[s][y] + a[x] + a[y];
        if(z == s)
        {
            o[r] = sum;
            r++;
        }
        else
        {
            sum += b[z][p] + b[s][p];
            o[r] = sum;
            r++;
        }
    }
    for (int i = 0; i < r; i++)
    {
        cout << o[i] << endl;
    }
}

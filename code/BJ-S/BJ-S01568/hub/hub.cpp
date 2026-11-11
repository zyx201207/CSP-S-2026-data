#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int read()
{
    int mul = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
    {
        mul = (mul << 1) + (mul << 3) + int(c - '0');
        c = getchar();
    }
    return mul;
}
int way[1010][1010], minn[1010];
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    c = read();
    t = read();
    int lastn = 0;
    while (t--)
    {
        int n, k;
        n = read();
        k = read();
        if (k != 2) cout << 1 << "\n";
        for (register int i = 1; i <= n; ++i) for (register int j = 1; j <= n; ++j) way[i][j] = 999999999;
        for (register int i = 1; i <= n; ++i)
        {
            int b, e;
            b = read();
            e = read();
            way[i][i] = 0;
            way[b][e] = 1;
        }
        for (register int k = 1; k <= n; ++k)
        {
            for (register int i = 1; i <= n; ++i)
            {
                for (register int j = i + 1; j <= n; ++j)
                {
                    way[i][j] = min(way[i][j], way[i][k] + way[k][j]);
                    minn[i] = max(way[i][j], minn[i]);
                }
            }
        }
        sort(minn + 1, minn + n + 1);
        cout << minn[2] << "\n";
    }

    return 0;
}

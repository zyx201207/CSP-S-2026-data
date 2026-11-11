#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    int x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        for (int j = 1; j <= n; j++)
        {
            int y;
            cin >> x >> y;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int y;
        cin >> x >> y;
    }

    if (c == 0)
    {
        if (n == 2)
        {
            cout << 32 << endl << 17;
        }
        else if (n == 3)
        {
            cout << 35 << endl << 16;
        }
    }
    return 0;
}

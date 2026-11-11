#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
long long w[505], t[505][50005], r[10005][2];
/*/
long long du()
{
    int x, f = 1;
    char s = getchar();
    while (s < '0' || s > '9')
    {
        if (s == '-')
        {
            f = -1;
        }
        s = getchar();
    }
    while (s >= '0' && s <= '9')
    {
        x = x * 10 + s - '0';
        s = getchar();
    }
    return x * f;
}
/*/
int main()
{
    cin.tie(0);
    cout.tie(0);
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    //in
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int l;
            cin >> l;
            cin >> t[l][j];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> r[i][0] >> r[i][1];
    }
    if (c >= 12 && c <= 15)
    {
        for (int i = 1; i <= q; i++)
        {
            int T = t[1][1];
            cout << w[r[i][0]] + w[r[i][1]] + (2 * T) << endl;
        }
    }
    else
    {
        for (long long i = 1; i <= q; i++)
        {
            cout << w[r[i][0]] + w[r[i][1]] + t[r[i][0]][1] + t[r[i][1]][1] << endl;
        }
    }
    return 0;
}

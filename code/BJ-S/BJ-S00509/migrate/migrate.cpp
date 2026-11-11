#include <iostream>
using namespace std;

long long x[2000010], f[2000010], g[2000010];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t, n, d;
    cin >> c >> t;
    while (t--)
    {
        long long cnt = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        if (c == 11 || c == 12)
        {
            cout << n << " ";
            if (n <= 3 || d < 2 * (x[2] - x[1]))  cout << 0 << endl;
            else  cout << max(0ll, n - 2 * (d / (x[2] - x[1])) + 1) << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                f[i] = 0, g[i] = 1;
                for (int j = i + 1; j <= n; j++)
                {
                    if (x[j] - x[j - 1] > d)  break;
                    g[j] = 0;
                    int r = j - 1, l = i;
                    while (l < r)
                    {
                        int mid = (l + r) / 2;
                        if (x[j] - x[mid] <= d)  r = mid;
                        else  l = mid + 1;
                    }
                    f[j] = f[l] + 1;
                    for (int k = l; k < j; k++)
                    {
                        if (f[k] + 1 == f[j])  g[j] += g[k];
                        if (f[k] + 1 > f[j] || g[j] > 2)  break;
                    }
                    if (g[j] == 2)  cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
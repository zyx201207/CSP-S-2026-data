#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long a[2000005];
long long b[500005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t;
    cin >> c >> t;
    if (1 <= c && c <= 10)
    {
        while (t--)
        {
            long long n, d, ans = 0;
            cin >> n >> d;
            for (int i = 1; i <= n; ++i)
            {
                cin >> a[i];
            }
            for (int i = 1; i <= n - 1; ++i)
            {
                for (int j = i + 1; j <= n; ++j)
                {
                    if (a[j] - a[i] < 2 * d && a[j] - a[i] > d && (a[j] - a[i]) - (a[j] - a[j - 1]) <= d && (a[j] - a[i]) > (d - 1) * 2 && abs(i - j) != 1 && a[i] - a[i - 1] <= d)
                    {
                        ans++;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    else if (11 <= c && c <= 12) //A
    {
        
    }
    else if (13 <= c && c <= 14) //B
    {

    }
    else if (15 <= c && c <= 18) //C
    {

    }
    else if (19 <= c && c <= 25)
    {

    }
    return 0;
}

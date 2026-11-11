#include <iostream>
using namespace std;

long long a[2000005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    long long c, t;
    cin >> c >> t;

    if (11 <= c && c <= 12 || c == 0)
    {
        for (long long i = 1; i <= t; i++)
        {
            long long n, d;
            cin >> n >> d;

            for (long long i = 1; i <= n; i++)
            {
                cin >> a[i];
            }

            if (a[2] - a[1] <= d / 2)
            {
                cout << n - d / (a[2] - a[1]) << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }

        return 0;
    }
    return 0;
}
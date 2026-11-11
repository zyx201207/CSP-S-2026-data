#include <bits/stdc++.h>

using namespace std;

const long long maxn = 2e6 + 10;

long long n, d, c, t;
long long a[maxn];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long i, j, s, t;

    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (i = 1; i <= n; i++) cin >> a[i];

        //if (c == 11 || c == 12)
        {
            if (n == 1)
            {
                cout << "0\n";
                continue;
            }
            long long dt = a[2] - a[1];
            long long k = d / dt;
            if (k <= 1)
            {
                cout << "0\n";
                continue;
            }
            cout << max(0ll, n - 2 * k + 1) << '\n';
        }
    }

    return 0;
}

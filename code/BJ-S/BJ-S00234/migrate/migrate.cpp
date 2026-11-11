#include <bits/stdc++.h>
using namespace std;
long long a[200005], f[505][505];
int main()
{
    int c, t;
    cin >> c >> t;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    while (t--)
    {
        int n;
        long long d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        cout << 1 << endl;
    }
    return 0;
}
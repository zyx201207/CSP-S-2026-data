#include <iostream>
using namespace std;

int a[2000010], c, t;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (a[1] + a[2] + a[3] == a[2] * 3) cout << n - d / (a[2] - a[1]) * 2 + 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll c, t;
ll n, d, a[2000001];
bool Special_A() {
    if (n == 1 || n == 2) return true;
    int k = a[2] - a[1];
    for (int i = 3; i < n; ++i)
        if (a[i + 1] - a[i] != k) return false;
    return true;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        if (d == 1) {
            cout << 0 << '\n';
            continue;
        }

        if (Special_A()) {
            int k = a[n] - a[n - 1];
            if (d >= 2 * k) {
                int i = 2;
                while (++i)
                    if (0 <= d - i * k && d - i * k <= k) cout << (n - i) * k + 1;
            } else {
                cout << 0 << '\n';
                continue;
            }

        }
        else cout << 0 << '\n';

    }

    return 0;
}

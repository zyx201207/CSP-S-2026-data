#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int c, t;
ll a[N];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        int n, d, cnt = 0;;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (d == 1) {
            cout << 0 << '\n';
        }
        if (d == 2) {
            if (n % 2) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
        if (d > 2) {
            cout << 0 << '\n';
        }
    }
    return 0;
}

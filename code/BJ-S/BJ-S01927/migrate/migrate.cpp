#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int c, t;
int a[N], f[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n <= 3) {
            cout << 0 << endl;
            return 0;
        }
        f[1] = f[2] = 0;
        f[3] = 0;
        for (int i = 4; i <= n; i++) f[i] = max(f[i - 1], f[i - d] + a[i - d] - 1);
        cout << f[n] << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 20000100;
int t, a;
int f[N], c[N], x[N];
bool ch (int e, int d) {
    if (c[e] - d >= c[e-2]) {
        return false;
    }
    if (c[e-1] - d >= c[e-3]) {
        return false;
    }
    return true;
}
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> a >> t;
    while (t--) {
        int n, b;
        cin >> n >> b;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            f[i] = 0;
            x[i] = false;
        }
        for (int i = 1; i <= 3; i++) {
            f[i] = 0;
        }
        for (int i = 4; i <= n; i++) {
            if (ch(i, b)) {
                f[i] += 1;
                x[i] = true;
            }
            if (c[i] - b > c[i - 2] && x[i-1] && c[i] - b <= c[i-1]) {
                f[i] += 1;
                x[i] = true;
            }
        }
        cout << f[n] << endl;
    }
    return 0;
}

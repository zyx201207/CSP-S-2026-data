#include <bits/stdc++.h>
#define int long long
using namespace std;

int isl[2000005];

int meth, n, d;

void solve() {
    int cnt = 0;
    cin >> n >> d;
    for (int i = 0;i < n;i++) {
        cin >> isl[i];
    }
    int dt = isl[n-1] - isl[n-2];
    if (dt * 2 > d) {
        cout << 0 << endl;
        return;
    }
    int a = 1;
    while ((dt * a / d != 1) || (dt * a / d == 1 && (dt * a) % d == 0)) {
        a++;
    }
    cout << n - a - 1 << endl;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}

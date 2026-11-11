#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 2;
int c, T, n, d, x[N];
void sola () {
    int ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    int gc = x[2] - x[1];
    int bro = d / gc;
    if (bro == 0) {
        cout << 0 << '\n';
        return;
    }
    int zhou = bro * 2 - 1;
    for (int l = 1; l + zhou <= n; l++) {
        int r = l + zhou;
        ans++;
    }
    cout << ans << '\n';
    return;
}
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--) {
        sola();
    }
    return 0;
}
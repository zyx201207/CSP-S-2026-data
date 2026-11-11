#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long

int c, t, k, n, a[15], ans = 9e18;
bool vis[15];

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
    }
    if (n - k <= 2) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--)
        solve();
    return 0;
}

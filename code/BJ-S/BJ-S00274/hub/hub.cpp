#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];

int c, t;
int n, k;

signed main() {
    //freopen("hub5.in", "r", stdin);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (c == 0) {
            if (k == n) cout << 0 << "\n";
            else if (k >= (n - 1) / 2) cout << 1 << "\n";
            else cout << (n - 1) / 2 - k + 1 << "\n";
        }
    }
    return 0;
}

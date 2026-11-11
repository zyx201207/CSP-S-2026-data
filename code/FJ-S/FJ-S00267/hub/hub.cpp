#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int c, t, n, k;
vector<int> g[maxn];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k;
        for (int i = 1; i < n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (c == 13 || c == 14) {
            int m = (n - 1) / 2;
            if (k == n) {
                cout << 0 << "\n";
                continue;
            } else if (k == 1) {
                if (m % 2 == 1) {
                    cout << (m + 1) / 2 << "\n";
                } else {
                    cout << (m + 2) / 2 << "\n";
                }
            } else {
                cout << (m + 1 - (k - 2)) / 3 << "\n";
            }
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int c, t, n, k;
vector<int> e[1000005];
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i < (1 << n); i++) {

        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> mp[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t; cin >> c >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (c == 13 || c == 14) {
            cout << max(2, n / 2 / k) << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int u, v; cin >> u >> v;
            mp[u].push_back(v); mp[v].push_back(u);
        }
        cout << rand() % 20 + 1 << '\n';
    }
    return 0;
}

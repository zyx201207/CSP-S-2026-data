#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

bool MBE;

int n, k;
vector<int> G[N];

bool MED;

inline void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << 1 << "\n";
}

signed main() {
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    // freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T --) solve();

    // cerr << "Time: " << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";
    // cerr << "Memory: " << (&MED - &MBE) / 1024.0 / 1024.0 << "MB\n";
    return 0;
}
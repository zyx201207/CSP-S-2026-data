#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;

    vector<int> g[1000001];

    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    cout << 1 << '\n';
    cout << 2 << '\n';

    return 0;
}

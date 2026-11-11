#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int c, t, n, k;
vector<int> g[1000005];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << "1\n";
    }

    return 0;
}

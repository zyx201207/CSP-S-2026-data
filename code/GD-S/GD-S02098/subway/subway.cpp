#include<bits/stdc++.h>
using namespace std;

constexpr int N = 505;
constexpr int M = 5e5 + 7;

int c, n, m, d, q;
int w[N];
int fa[205][N];
vector<int> a[N];
vector<int> t[N];
 
int find(int x, int z) { return x == fa[z][x] ? x : fa[z][x] = find(fa[z][x]); }

void union(int x, int y) {
    x = find(x), y = find(y);
    fa[y] = x;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, y; cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }


    while (q--) {
        int u, v; cin >> u >> v;
        int ans = w[u] + w[v];
        cout << ans << "\n";
    }


    return 0;
}


/*

5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

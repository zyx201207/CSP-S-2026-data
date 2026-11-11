#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5, M = 5e5 + 5;
int c, n, m, d, Q, a[N][M], t[N][M], w[M], k[N];
struct node {
    int v, w;
} ;
vector <node> g[M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            for (int l = 1; l <= j; l++) {
                g[a[i][l]].emplace_back(node{a[i][j], t[i][l]});
                g[a[i][j]].emplace_back(node{a[i][l], t[i][j]});
            }
        }
    }
    while (Q--) {
        int x, y;
        cin >> x >> y;
        bool f = 1;
        int dist = 0;
        queue <node> q;
        q.push({x, w[x] + w[y]});
        while (q.size()) {
            node r = q.front();
            int u = r.v, p = r.w;
            q.pop();
            for (auto s : g[u]) {
                int idx = 0;
                int v = s.v, w = s.w, _;
                for (auto __ : g[v]) 
                    if (__.v == u) _ = __.w;
                q.push({v, p + w + _});
                if (v == y) {
                    f = 0;
                    dist = p + w;
                    break;
                }
            }
            if (f == 0) break;
        }
        cout << dist << '\n';
    }
    return 0;
}
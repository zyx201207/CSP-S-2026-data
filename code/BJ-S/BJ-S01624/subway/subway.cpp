#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int v;
    ll w;
};
vector<node> g[505005];
ll c, n, m, d1, q1, w[500005], d[500005];
struct edge {
    ll u, t;
    bool operator < (const edge &other) const {
        return t > other.t;
    }
};
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d1 >> q1;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k, c[500005];
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int v, w;
            cin >> v >> w;
            g[v].push_back({499000 + i, w});
            g[499000 + i].push_back({v, w});
        }
    }
    while(q1--) {
        ll x, y;
        cin >> x >> y;
        priority_queue<edge> q;
        q.push({x, 0});
        memset(d, 0x3f3f3f3f3f3f3f3f, sizeof(d));
        d[x] = 0;
        while(!q.empty()) {
            ll u = q.top().u, t = q.top().t;
            q.pop();
            if(t != d[u]) {
                continue;
            }
            for(int i = 0; i < g[u].size(); i++) {
                ll v = g[u][i].v, w = g[u][i].w;
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    q.push({v, d[v]});
                }
            }
        }
        cout << d[y] + w[x] + w[y] << endl;
    }
    return 0;
}

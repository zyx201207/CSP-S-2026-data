#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, M = 5e5 + 10;
int w[M], k[N], dis[M];

struct strt {
    int l, cur;
};
vector<strt> g[N];
vector<int> a[N], t[N];
bool vis[M];

struct Node {
    int u, dis;
    bool operator >(Node y)const {
        return dis > y.dis;
    }
};
priority_queue<Node, vector<Node>, greater<Node> > pq;

void dijk(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq.push({s, 0});
    vis[s] = true;
    while (pq.size()) {
        Node x = pq.top();
        pq.pop();
        for (strt p : g[x.u]) {
            for (int i = 0; i < a[p.l].size(); ++i) {
                int v = a[p.l][i];
                if (vis[v]) continue;
                if (x.dis + t[p.l][i] + t[p.l][i] < dis[v]) {
                    dis[v] = x.dis + t[p.l][i] + t[p.l][i];
                    pq.push({v, dis[v]});
                }
                vis[v] = true;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int u, v;
            cin >> u >> v;
            a[i].push_back(u);
            g[u].push_back({i, j});
            t[i].push_back(v);
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        dijk(x);
        cout << w[x] + w[y] + dis[y] << "\n";
    }
    return 0;
}

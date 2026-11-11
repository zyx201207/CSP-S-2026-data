#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MAXN = 400005;
struct Edge {
    int to;
    ll w;
    Edge(int t, ll ww) : to(t), w(ww) {}
};
vector<Edge> g[MAXN];
ll dis[MAXN];
bool vis[MAXN];
void dijkstra(int s, int n_node) {
    for(int i = 1; i <= n_node; i++) {
        dis[i] = INF;
        vis[i] = false;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        ll d = q.top().first;
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto &e : g[u]) {
            int v = e.to;
            if(dis[v] > d + e.w) {
                dis[v] = d + e.w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<ll> w(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int cur_id = m + n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int L = m + i;
        for(int j = 1; j <= k; j++) {
            int a;
            ll t;
            cin >> a >> t;
            cur_id ++;
            int platform = cur_id;
            int hall_a = a;
            g[hall_a].emplace_back(platform, t);
            g[platform].emplace_back(hall_a, t);
            g[platform].emplace_back(L, 0);
            g[L].emplace_back(platform, 0);
        }
    }
    int total_node = cur_id;
    while(q--) {
        int x, y;
        cin >> x >> y;
        dijkstra(x, total_node);
        ll res = w[x] + dis[y] + w[y];
        cout << res << '\n';
    }
    return 0;
}

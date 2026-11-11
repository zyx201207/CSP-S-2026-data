#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <array>

namespace {
    typedef long long lnt;

    const int inf = 0x3f3f3f3f;

    const int _max_n = 9;
    const int max_n = 1 << _max_n;

    const int _max_m = 19;
    const int max_m = 1 << _max_m;

} // 题面好长啊 ...

// 线路编号为 i, 站台编号为 i + n

struct edge { int to; lnt v; };
struct node { int u; lnt d; };

bool operator <(const node &b, const node &a) {
    return a.d < b.d;
}

std::vector<edge> G[max_m];

void link(int a, int b, lnt v) {
    G[a].push_back({b, v});
    G[b].push_back({a, v});
    // std::printf("edge(%d, %d, %d)\n", a, b, v);
    // std::printf("edge(%d, %d, %d)\n", b, a, v);
}

int n, m, d, q; lnt w[max_m];
std::array<lnt, max_n> dis[max_n];
std::array<bool, max_n> vis;

void dij(int bg) {
	std::array<lnt, max_n> &_dis = dis[bg];
    std::fill(_dis.begin(), _dis.end(), lnt(inf) * inf);
	std::fill(vis.begin(), vis.end(), false);
    std::priority_queue<node> q;
    	
    q.push({bg, 0}), _dis[bg] = 0;

    while (!q.empty()) {
        node u = q.top(); q.pop();
        if (vis[u.u]) continue;
        vis[u.u] = true;
        for (const edge e : G[u.u]) {
            if (_dis[e.to] > u.d + e.v) {
                _dis[e.to] = u.d + e.v, q.push({e.to, u.d + e.v});
            }
        }
    }
}

void solve() {
    std::cin >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) std::cin >> w[i];
    
    for (int i = 1; i <= n; ++i) {
        int k; std::cin >> k;
        for (int e = 0; e < k; ++e) {
            int u; lnt t; std::cin >> u >> t;
            G[u + n].push_back({i, t});
            // std::printf("edge(%d, %d, %d)\n", u + n, i, t);
        }
    }

    for (int i = n + 1; i <= m + n; ++i) {
        for (int e = 0; e < int(G[i].size()); ++i) {
            for (int j = e + 1; j < int(G[i].size()); ++i) {
                link(G[i][e].to, G[i][j].to, G[i][e].v + G[i][j].v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        dij(i);
        // std::printf("%d: ", i);
        // for (int e = 1; e <= n; ++e) {
        // 	std::printf("%d ", dis[i][e]);
		// }
		// std::printf("\n");
    }

    for (int _i = 0; _i < q; ++_i) {
        int x, y; std::cin >> x >> y;
        lnt ans = lnt(inf) * inf; 
        for (const edge i : G[x + n]) {
            for (const edge e : G[y + n]) {
                ans = std::min(ans, dis[i.to][e.to] + i.v + e.v);
            }
        }
        std::printf("%lld\n", ans + w[x] + w[y]);
    }

}

int main() {
    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1, c; std::cin >> c;
    for (int i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}
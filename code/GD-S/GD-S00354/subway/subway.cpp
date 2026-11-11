#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (b); i >= (int)(a); --i)
using LL = long long;
using Pii = pair<int, int>;
#define fst first
#define snd second
#define pb push_back

namespace gdb7
{
	LL w[500010], d;
	LL dis[500010];
	vector<pair<int, LL> > lines[510];
	vector<pair<int, LL> > lineid[500010];
	struct Node {
		int u;
		LL w;
		bool operator<(const Node &rhs) const {
			return w > rhs.w;
		}
	};
	signed main(void) {
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		int c, n, m, d, q;
		scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
		rep (i, 1, m) {
			scanf("%d", w + i);
		}
		rep (i, 1, n) {
			int k;
			scanf("%d", &k);
			lines[i].reserve(k);
			rep (j, 1, k) {
				int a, t;
				scanf("%d%d", &a, &t);
				lines[i].pb((Pii){a, t});
				lineid[a].pb((Pii){i, t});
			}
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			rep (i, 1, m) {
				dis[i] = 4e18;
			}
			std::priority_queue<Node> pq;
			pq.push((Node){x, 0});
			dis[x] = 0;
			while (pq.size()) {
				int u = pq.top().u;
				if (dis[u] != pq.top().w) continue;
				pq.pop();
				if (u == y) {
					break;
				}
				for (auto t1: lineid[u]) {
					int lid = t1.fst, in_t = t1.snd;
					for (auto t2: lines[lid]) {
						int v = t2.fst, out_t = t2.snd;
						if (v == u) continue;
						LL w = (LL)in_t + out_t;
//						cout << "Find Edge from " << u << " (dist: " << dis[u] << ") to " << v << " cost " << w << endl;
//						cout << "Compare: current dist[v(" << v << ")]: " << dis[v] << " dist[u(" << u << ")]: " << dis[u] << " edgecost: " << w << endl;
						if (dis[v] > dis[u] + w) {
							dis[v] = dis[u] + w;
//							cout << "Push in: vertex: " << v << " dist: " << dis[v] << endl;
							pq.push((Node){v, dis[v]});
						}
					}
				}
			}
			printf("%lld\n", w[x] + dis[y] + w[y]);
		}
		return 0;
	}
};

signed main()
{
	return gdb7::main();
}


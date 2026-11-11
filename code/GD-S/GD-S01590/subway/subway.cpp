#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PLI = pair<ll, int>;

namespace io {
	const int N = 1 << 20;
	char buf[N], *p = buf, *q = buf;
	
	inline int gc() {
		if (p == q) { q = (p = buf) + fread(buf, 1, N, stdin); if (p == q) return EOF; }
		return (unsigned char)*p++;
	}
	
	template<typename T>
	inline bool read(T &x) {
		x = 0; int f = 1, c = gc();
		while (c < '0' || c > '9') { if (c == EOF) return 0; if (c == '-') f = -1; c = gc(); }
		while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = gc();
		x *= f;
		return 1; 
	}
}
using io::read;

const int N = 5e5 + 550; // 地铁站 + 线路总结点数 
ll w[N]; 
vector<PLI> g[N];
int c, n, m, d, q;

ll dist[N];
bool vis[N];
void dijkstra(int s) {
	for (int i = 1; i <= n + m + 5; i++) dist[i] = 0x3f3f3f3f3f3f3f3f;
	memset(vis, 0, sizeof(vis));
	priority_queue<PLI, vector<PLI>, greater<PLI>> pq; pq.push({0, s}); dist[s] = 0;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e : g[u]) {
			int v = e.second; ll w = e.first;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	read(c); read(n); read(m); read(d); read(q);
	for (int i = 1; i <= m; i++) read(w[i]);
	
	for (int i = 1, k; i <= n; i++) {
		read(k);
		for (int j = 1, a, t; j <= k; j++) {
			read(a); read(t);
			g[a].push_back({t, m + i});
			g[m + i].push_back({t, a});
		}
	}
	
	for (int i = 1, x, y; i <= q; i++) {
		read(x), read(y);
		dijkstra(x);
		cout << dist[y] + w[x] + w[y] << "\n";
	}

	return 0;
}


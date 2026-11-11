#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e6 + 100, M = 6e5 + 100;

typedef long long ll;

int c, n, m, d, q;
int h[N], ne[N], ver[N], tot;
ll wgt[N];

ll W[N];
vector<int> vec[N];

ll dis[510][510];

void add (int u, int v, int w) {
	ver[ ++ tot] = v, wgt[tot] = w, ne[tot] = h[u], h[u] = tot;
}

typedef pair<ll, int> PLI;

bool vis[510];

void dijkstra (int S) {
	priority_queue<PLI, vector<PLI>, greater<PLI> > heap;
	heap.push({0ll, S});
	memset(dis[S], 0x3f, sizeof dis[S]);
	memset(vis, 0, sizeof vis);
	dis[S][S] = 0;
	while (heap.size()) {
		int u = heap.top().second; heap.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u + m]; i; i = ne[i]) {
			int v1 = ver[i]; ll w1 = wgt[i];
			for (int i2 = h[v1]; i2; i2 = ne[i2]) {
				int v = ver[i2] - m; ll w2 = wgt[i2];
				if (dis[S][v] > dis[S][u] + w1 + w2) {
					dis[S][v] = dis[S][u] + w1 + w2;
					heap.push({dis[S][v], v});
				}
			}
		}
	} 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ ) cin >> W[i];
	for (int i = 1; i <= n; i ++ ) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++ ) {
			ll v, w;
			cin >> v >> w;
			add (m + i, v, w); add(v, m + i, w);			
		}
	}
	
	for (int i = 1; i <= n; i ++ ) dijkstra(i);

	while (q -- ) {
		ll ans = 0x3f3f3f3f3f3f3f3f;
		int u, v;
		cin >> u >> v;
		for (int i = h[u]; i; i = ne[i]) {
			int U = ver[i]; ll w1 = wgt[i];
			for (int i2 = h[v]; i2; i2 = ne[i2]) {
				int V = ver[i2]; ll w2 = wgt[i2];
				ans = min(ans, dis[U - m][V - m] + w1 + w2 + W[u] + W[v]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<long long, int> PII;

const int maxn = 5e5 + 2005;

struct Edge {
	int to, next, val;
} edge[maxn * 2];
int head[maxn], edgen;
int c, n, m, d, q, k, u, v, w[maxn];
long long dis[maxn];
int a, t;
long long ans[maxn];
bool vis[maxn];

struct Ask {
	int id, u, v;
	bool operator<(const Ask &other) {
		return u < other.u;
	}
} ask[maxn];

void addedge(int u, int v, int w) {
	edge[++edgen].to = v;
	edge[edgen].next = head[u];
	edge[edgen].val = w;
	head[u] = edgen;
}

priority_queue<PII, vector<PII>, greater<PII> > pq;
void dijkstra(int u) {
	// cerr << "start = " << u << ": ";
	while(pq.size()) pq.pop();
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	pq.emplace(0, u);
	while(pq.size()) {
		auto u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			dis[v] = min(dis[v], dis[u] + edge[i].val);
			pq.emplace(dis[v], v);
		}
	}
	// for(int i = 1; i <= n + m; i++) {
	// 	cerr << dis[i] << ' ';
	// }
	// cerr << '\n';
}

queue<int> que;
void bfs(int u) {
	while(que.size()) que.pop();
	memset(vis, 0, sizeof(vis));
	dis[u] = 0;
	que.push(u);
	while(que.size()) {
		int u = que.front();
		que.pop();
		for(int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			if(vis[v]) continue;
			dis[v] = dis[u] + edge[i].val;
			que.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k;
		if(k == 1) {
			cin >> a >> t;
			continue;
		}
		if(c >= 7 && c <= 11) {
			int aa, bb, cc, dd;
			cin >> aa >> bb >> cc >> dd;
			addedge(aa, cc, bb + dd);
			addedge(cc, aa, bb + dd);
		} else {
			for(int j = 1; j <= k; j++) {
				cin >> a >> t;
				addedge(a, m + i, t);
				addedge(m + i, a, t);
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		cin >> u >> v;
		if(u > v) swap(u, v);
		ask[i].u = u, ask[i].v = v, ask[i].id = i;
	}
	sort(ask + 1, ask + q + 1);
	for(int i = 1; i <= q; i++) {
		if(i == 1 || ask[i].u != ask[i - 1].u) {
			if(c >= 12 && c <= 19) bfs(ask[i].u);
			else dijkstra(ask[i].u);
		}
		ans[ask[i].id] = 
			dis[ask[i].v] + w[ask[i].u] + w[ask[i].v];
	}
	for(int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
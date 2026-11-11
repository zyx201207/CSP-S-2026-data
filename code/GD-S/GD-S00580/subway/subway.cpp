#include<bits/stdc++.h>
using namespace std;
const int N = 510;
struct edge{
	long long v, w;
};
vector<edge> g[500000];
long long cnt;
long long c, n, m, d, q;
struct node{
	long long u, dis;
	bool operator < (const node &x) const {
		return dis > x.dis;
	}
};

long long dis[500000];
void dijkstra(int s, int t) {
	priority_queue<node> pq;
	pq.push({s, 0});
	memset(dis, 0x3f, sizeof dis);
	while(!pq.empty()) {
		node a = pq.top();
		pq.pop();
		long long u = a.u, d = a.dis;
		if(d > dis[u]) continue;
		dis[u] = d;
		if(u == t) break;
		for(auto e : g[u]) {
			long long v = e.v, w = e.w;
			if(dis[v] > d + w) pq.push({v, d + w});
		}
	}
	return;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	cnt = m;
	long long k, v, w;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &w);
		cnt++;
		g[i].push_back({cnt, w});
		g[cnt].push_back({i, w});
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k);
		cnt++;
		for(int j = 1; j <= k; j++) {
			scanf("%d%d", &v, &w);
			g[cnt].push_back({v + m, w});
			g[v + m].push_back({cnt, w});
		}
	}
	int s, t;
	while(q--) {
		scanf("%d%d", &s, &t);
		dijkstra(s, t);
		printf("%d\n", dis[t]);
	}
	return 0;
} 

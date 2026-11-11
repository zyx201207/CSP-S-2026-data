#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const int N = 505;
const int M = 5e5 + 5;

int c, n, m, d, q; //n:edge, m:node
int cnt, head[M * 2];
ll dist[M * 2];
 

struct Node {
	int v, next;
	ll w;
}edge[M * 4];

void add(int u, int v, ll w) {
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void dijkstra(int s) {
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int u = cur.second;
		if (dist[u] != cur.first) continue;
		for (int i = head[u];i != -1;i = edge[i].next) {
			int v = edge[i].v;
			ll w = edge[i].w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	memset(head, -1, sizeof(head));
	for (int i = 1;i <= m;i++) {
		ll w;
		cin >> w;
		add(i, m + i, w);
		add(m + i, i, w);
	}
	
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		vector<pair<int, ll>> vec;
		while (k--) {
			int a;
			ll w;
			cin >> a >> w;
			vec.push_back(make_pair(a, w));
		}
		for (int j = 0;j < vec.size();j++) {
			int u = vec[j].first + m;
			ll w1 = vec[j].second;
			for (int k = j + 1;k < vec.size();k++) {
				int v = vec[k].first + m;
				ll w2 = vec[k].second;
				add(u, v, w1 + w2);
				add(v, u, w1 + w2);
			}
		}
	}
	
	
	while (q--) {
		memset(dist, 0x3f, sizeof(dist));
		int s, e;
		cin >> s >> e;
		dijkstra(s);
		cout << dist[e] << '\n';
	}
	
	return 0;
}

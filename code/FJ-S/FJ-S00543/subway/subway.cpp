#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5 + 10;
int c, n, m, d, q;
int w[M];
int p[M];
int point[N];
int dist[N];
bool st[N];
//struct node {
//	int po, t;
//}a[N][N];
int find(int x) {
	if(p[x] != x) {
		return find(p[x]);
	}
	return p[x];
}
int dji(int u, int t) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(u);
	dist[u] = w[u];
	while(pq.size()) {
		u = pq.top();
		pq.pop();
		if(st[u]) continue;
		st[u] = 1;
		for(int i = 1; i <= n; i ++) {
			if(i != u && find(i) == find(u)) {
				dist[i] = min(dist[i], dist[u] + point[i]);
				pq.push(i);
			}
			if(i == t) {
				return dist[i] + w[t];
			}
		}
	}
	return dist[t] + w[t];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for(int i = 1; i < N; i ++) {
		p[i] = i;
	}
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		int last;
		for(int j = 1; j <= k; j ++) {
			//cin >> a[i][j].p >> a[i][j].t;
			int po, t;
			cin >> po >> t;
			point[po] = t;
			if(j != 1)
				if(find(p[po]) != find(p[last])) {
					p[po] = find(p[last]);
				}
			last = po;
//				if(find(p[a[i][j]]) != find(p[a[i - 1][j])]) {
//					p[a[i][j].p] = find(p[a[i - 1][j].p); 
//				}
		}
	}
	while(q --) {
		int x, y;
		cin >> x >> y;
		if(find(x) == find(y)) 
			cout <<	w[x] + w[y] + point[x] + point[y] << '\n';
		else {
			cout << dji(x, y) << '\n';
		}
	}
	return 0;
}

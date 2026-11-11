//GZ-S00003 贵阳市白云区华师一学校 殷浩然 
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for(int i = l; i <= r; i++)
#define dww(i, l, r) for(int i = l; i >= r; i--)
#define PII pair<int, int>
#define ub push_back
#define x first
#define y second
using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5;

int c, n, m, d, q;
int w[M];
vector<PII> sub[M];
vector<PII> edge[N];
int dist[N][N];

void dijkstra(int S) {
	memset(dist[S], 0x3f, sizeof dist[S]);
	dist[S][S] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, S});
	while(heap.size()) {
		auto t = heap.top();
		heap.pop();
		int u = t.y;
		if (dist[S][u] != t.x) continue;
		for (auto tt : edge[u]) {
			int v = tt.x, w = tt.y;
			if (dist[S][v] > dist[S][u] + w) {
				dist[S][v] = dist[S][u] + w;
				heap.push({dist[S][v], v});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	upp(i, 1, m) cin >> w[i];
	upp(i, 1, n) {
		int k;
		cin >> k;
		while(k--) {
			int x, y;
			cin >> x >> y;
			sub[x].ub({i, y});
		}
	}
	upp(i, 1, m) {
		for (auto t1 : sub[i]) {
			int v1 = t1.x, w1 = t1.y;
			for (auto t2 : sub[i]) {
				int v2 = t2.x, w2 = t2.y;
				if (v1 == v2) continue;
				edge[v1].ub({v2, w1 + w2});
				edge[v2].ub({v1, w1 + w2});
			}
		}
	}
	upp(i, 1, n) dijkstra(i);
	while(q--) {
		int x, y;
		cin >> x >> y;
		int res = 1e18;
		for (auto t1 : sub[x]) {
			int v1 = t1.x, w1 = t1.y;
			for (auto t2 : sub[y]) {
				int v2 = t2.x, w2 = t2.y;
				res = min(res, w1 + dist[v1][v2] + w2);
			}
		}
		cout << res + w[x] + w[y] << endl;
	}
	
	return 0;
}

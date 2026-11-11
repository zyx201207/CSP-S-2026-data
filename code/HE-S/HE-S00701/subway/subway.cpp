#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e5 + 10;
set<int> edge[510];
int w[N];
vector<PII> e[510]; 
int k[510]; 
bool st[510];
int d[510];
vector<int> a[510];
map<int, int> t[510];
int dijkstra(int S, int T) {
	memset(d, 0x3f, sizeof d);
	memset(st, 0, sizeof st);
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0, S});
	d[S] = 0;
	while (heap.size()) {
		int u = heap.top().second;
		heap.pop();
		if (st[u]) continue;
		st[u] = true;
		for (auto it : e[u]) {
			int j = it.first, dist = d[u] + it.second;
			if (d[j] > dist) {
				d[j] = dist;
				heap.push({d[j], j});
			} 
		}
	}
	return d[T];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			int x;
			cin >> x;
			cin >> t[i][x];
			a[i].push_back(x);
			edge[i].insert(x);
		}
	} 
	for (int i = 1; i <= n; i ++) {
		for (int j : a[i]) {
			for (int r = 1; r <= n; r ++) {			
				if (i == r) continue;
				if (edge[r].count(j)) e[i].push_back({r, t[i][j] + t[r][j]});
			}
		}
	}
	while (q --) {
		int a, b, S, T;
		cin >> a >> b; 
		int ans = 0;
		bool flag = false;
		for (int i = 1; i <= n; i ++) {
			if (edge[i].count(a) && edge[i].count(b)) flag = true, S = T = i;
		}
		if (flag) {
			cout << t[S][a] + w[a] + t[T][b] + w[b] << '\n'; 
			continue;
		}
		for (int i = 1; i <= n; i ++) {
			if (edge[i].count(a)) S = i;
			if (edge[i].count(b)) T = i;
		}
		ans = t[S][a] + w[a] + t[T][b] + w[b] + dijkstra(S, T);
		cout << ans << '\n';
	}
	return 0;
} 

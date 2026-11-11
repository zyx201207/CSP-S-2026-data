#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 5, INF = 1e9;

int c, T, n, k, ans, cnt;
int f[N], flag[N], dist[N], a[N], b[N];
vector<int> g[N]; 
queue<int> q;

void Clear() {
	ans = INF, cnt = 0;
	for (; !q.empty(); q.pop()) ;
	for (int i = 1; i <= n; i++) {
		f[i] = flag[i] = dist[i] = a[i] = b[i] = 0;
		g[i].clear();
	}
	return ;
}

int Find(int x) {
	return f[x] == x ? x : f[x] = Find(f[x]);
}

void Merge(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if (fx == fy) return ;
	f[fx] = fy;
	return ;
}

void DFS(int u, int m) {
	if (u == n + 1) {
		if (m != k) {
			return ;
		}
		for (int i = 1; i <= n; i++) f[i] = i;
		for (int u = 1; u <= n; u++) {
			for (int v : g[u]) {
				if (flag[v] == flag[u]) {
					Merge(v, u);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i == Find(i)) {
				cnt += flag[i] == 1;
			}
		}
		if (cnt > 2) return ;
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
			if (flag[i]) {
				q.push(i);
				dist[i] = 0;
			}
		}
		for (; !q.empty(); ) {
			int u = q.front();
			q.pop();
			for (int v : g[u]) {
				if (dist[v] == INF) {
					dist[v] = dist[u] + 1;
					q.push(v); 
				}
			}
		}
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, dist[i]);
		}
		ans = min(ans, mx);
		return ;
	}
	flag[u] = 1;
	DFS(u + 1, m + 1);
	flag[u] = 0;
	DFS(u + 1, m);
	return ;
}

void DFS(int u, int f, int d) {
	a[u] = INF;
	b[u] = 0;
	for (int v : g[u]) {
		if (v != f) {
			DFS(v, u, d);
			a[u] = min(a[u], a[v] + 1);
			b[u] = max(b[u], b[v] + 1);
		}
	}
	if (a[u] + b[u] <= d) b[u] = -INF;
	if (b[u] == d) {
		cnt++;
		a[u] = 0;
		b[u] = -INF; 
	}
	return ;
}

int Check(int x) {
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = b[i] = 0;
	}
	DFS(1, 0, x);
	if (b[1] != -INF) cnt++;
//	cout << x << ' ' << cnt << '\n';
	return cnt <= k;
}

void Solve() {
	Clear();
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (c <= 3) {
		DFS(1, 0);
		cout << ans << '\n';
	} else {
		int l = 1, r = n;
		for (; l < r; ) {
			int mid = l + r >> 1;
			Check(mid) ? r = mid : l = mid + 1;
		}
		cout << l << '\n';
	}
	return ;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	for (cin >> c >> T; T--; Solve()) ;
	return 0;
}


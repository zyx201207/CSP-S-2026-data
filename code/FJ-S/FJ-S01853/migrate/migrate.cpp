#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

inline ll read () {
	int w = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		w = w * 10 + c - '0';
		c = getchar();
	}
	return w * f;
}

const int mxn = 5e5 + 5;

ll x[mxn];
int dis[mxn];
bool vis[mxn];
int cnt[mxn];

ll n, d;

void dij (int s) {
	dis[s] = 0;
	cnt[s] = 1;
	priority_queue<p, vector<p>, greater<p> > q;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		vis[u] = 1;
		for (int v = u + 1; v <= n && x[v] - x[u] <= d; v++) {
			if (vis[v]) continue;
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				q.push({dis[v], v});
			}
		}
	}
	for (int u = s; u < n; u++) {
		for (int v = u + 1; v <= n && x[v] - x[u] <= d; v++) {
			if (dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
		}
	}
}

void solve () {
	n = read();
	d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	sort(x + 1, x + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		fill(dis + i, dis + 1 + n, 1e9);
		fill(vis + i, vis + 1 + n, 0);
		fill(cnt + i, cnt + 1 + n, 0);
		dij(i);
		for (int j = 1 + i; j <= n; j++) {
			ans += (cnt[j] == 2);
		}
	}
	printf("%d\n", ans);
}

void solve2 () {
	n = read();
	d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	sort(x + 1, x + 1 + n);
	for (int w = 1; w <= 10; w++) {
		
	}
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read();
	int t = read();
	while (t--) {
		if (n <= 5000) solve();
		else solve2();
	}
	return 0;
}

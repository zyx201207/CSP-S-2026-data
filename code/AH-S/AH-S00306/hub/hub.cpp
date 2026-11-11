#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int c, T, n, k, f[N], vis[N], t[N], ans;
vector <int> G[N];

int calc() {
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		t[i] = -1;
		if (f[i]) {
			t[i] = 0;
			q.push(i);
		}
	}
	int res = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		res = max(res, t[u]);
		for (int i = 0; i < (int)G[u].size(); i++) {
			int v = G[u][i];
			if (t[v] == -1)	q.push(v), t[v] = t[u] + 1;
		}
	}
	return res;
}

void bfs(int s) {
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)G[u].size(); i++) {
			int v = G[u][i];
			if (vis[v])	q.push(v), vis[v] = 0;
		}
	}
	return ;
}

bool check() {
	for (int i = 1; i <= n; i++)	vis[i] = f[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			cnt++, vis[i] = 0;
			if (cnt > 2)	return 0;
			bfs(i);
		}
	}
	return cnt <= 2;
}

void dfs(int step, int s) {
	if (s > k)	return ;
	if (step > n) {
		if (s != k)	return ;
		if (check())	ans = min(ans, calc());
		return ;
	}
	f[step] = 1;
	dfs(step + 1, s + 1);
	f[step] = 0;
	dfs(step + 1, s);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)	G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans = 1e9;
		dfs(1, 0);
		cout << ans << "\n";
	}
	
	return 0;
}

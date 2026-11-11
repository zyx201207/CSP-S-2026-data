#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> g[N];
vector<int> pp;

int temp;

long long bfs (int s) {
	unordered_map<int, bool> vis;
	unordered_map<int, int> step;
	long long res = 0;
	queue<int> q;
	q.push(s);
	step[s] = 0;
	vis[s] = true;

	temp = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (vis[v]) continue;
			step[v] = step[u] + 1;
			temp = max(temp, step[v]);
			vis[v] = true;
			res += step[v];
			q.push(v);
		}
	}
	return res;
}

int bfs_2 (int p, int l, int k) {
	unordered_map<int, bool> vis;
	unordered_map<int, int> step;
	queue<int> q;
	q.push(p);
	step[p] = 0;
	vis[p] = true;

	temp = 0;
	while (q.size()) {
		if (!k) return l - temp;
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (vis[v]) continue;
			step[v] = step[u] + 1;
			temp = max(temp, step[v]);
			if ((step[v] + 1) * 2 >= l && k) {
				pp.push_back(v);
				k--;
			}
			vis[v] = true;
			q.push(v);
		}
	}
}

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		long long ans = LLONG_MAX;
		int point;
		int maxn_l;
		for (int i = 1; i <= n; i++) {
			int ret = bfs(i);
			if (ret < ans) {
				point = i;
				ans = ret;
				maxn_l = temp;
			}
		}
		cout << bfs_2(point, maxn_l, k) << "\n";
	}
	return 0;
}


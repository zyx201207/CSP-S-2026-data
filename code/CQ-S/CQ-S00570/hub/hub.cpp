#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
const int N = 1000100;
int n, k;
vector<int> g[N];
int vis[N], dis[N], dis2[N], maxd[N];
void dfsvis(int u, int f) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (v == f) continue;
		dfsvis(v, u);
	}
}
void getdis(int s) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
	}
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (vis[v] && dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1, q.push(v);
			}
		}
	}
}
pair<int, int> gethv(int rt) {
	getdis(rt);
	int maxi = rt;
	for (int i = 1; i <= n; i++) {
		if (vis[i] && dis[i] > dis[maxi]) maxi = i;
	}
	getdis(maxi);
	int max2 = maxi;
	for (int i = 1; i <= n; i++) {
		if (vis[i] && dis[i] > dis[max2]) max2 = i;
		dis2[i] = dis[i];
	}
	getdis(max2);
	pair<int, int> res = {0, 0};
	for (int i = 1; i <= n; i++) {
		if (vis[i] && dis[i] + dis2[i] == dis[maxi]) {
			if (dis[i] == dis[maxi] / 2 || dis2[i] == dis[maxi] / 2) {
				if (!res.first) res.first = i;
				else res.second = i;
			}
		}
	}
	return res;
}
int maxx = 0;
void getmaxx(int u, int f, int X) {
	maxd[u] = 0;
	for (auto v : g[u]) {
		if (v != f && vis[v]) {
			getmaxx(v, u, X), maxd[u] = max(maxd[u], maxd[v] + 1);
		}
	}
	if (maxd[u] >= X) maxx++;
}
int ans = 1e9;
void getans(int u, int f, int X) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	dfsvis(u, f);
	pair<int, int> tmp = gethv(u);
	maxx = 0, getmaxx(tmp.first, 0, X);
	int k1 = maxx;
	if (tmp.second) maxx = 0, getmaxx(tmp.second, 0, X), k1 = min(k1, maxx);
	if (f) {
		for (int i = 1; i <= n; i++) vis[i] = 1 - vis[i];
		dfsvis(f, u);
		pair<int, int> tmp = gethv(f);
		maxx = 0, getmaxx(tmp.first, 0, X);
		int k2 = maxx;
		if (tmp.second) maxx = 0, getmaxx(tmp.second, 0, X), k2 = min(k2, maxx);
		ans = min(ans, k1 + k2);
	}
	else ans = min(ans, k1);
	for (auto v : g[u]) {
		if (v != f) getans(v, u, X);
	}
}
bool check(int x) {
	ans = 1e9;
	getans(1, 0, x);
	return ans <= k;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}

/*
binary search
2 blocks is not ez to deal with
1 block, and u in S in block 1, u in T in block 2
S is a block, T is a block
solve a block:
直径，中点，两个点，dfs两遍算答案
O(n*N*log)
*/
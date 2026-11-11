#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 1e6 + 10;
int n, k, dis[N];

int pre[N], idx;
struct node {
	int to, next;
} e[N];

inline void add(int u, int v) {
	e[++idx] = {v, pre[u]};
	pre[u] = idx;
	return ;
}

inline void init() {
	for (int i = 1; i <= n; i++) pre[i] = 0;
	idx = 0;
	return ;
}

int fa[N];
int find(int x) {
	return ((fa[x] ^ x) ? fa[x] = find(fa[x]) : x);
}

void dfs(int x, int fath, int dep) {
	dis[x] = min(dis[x], dep);
	for (int i = pre[x]; i; i = e[i].next) {
		int to = e[i].to;
		if (to == fath) continue;
		dfs(to, x, dep + 1);
	}
	return ;
}

inline void solve() {
	init();
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	int ans = 1e9;
	for (int bit = 1; bit < (1 << n); bit++) {
		bool f[N];
		int cnt = 0;
		vector<int> v;
		v.clear();
		for (int i = 1; i <= n; i++)
			if (bit & (1 << (i - 1))) {
				f[i] = true, cnt++;
				if (cnt > k) break;
				v.push_back(i);
			} else f[i] = false;
//		for (auto x : v) cout << x << " ";cout << endl;
		if (cnt != k) continue;
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (auto x : v) {
			for (int i = pre[x]; i; i = e[i].next) {
				int to = e[i].to;
				if (f[to]) {
					int fu = find(x), fv = find(to);
					if (fu != fv) fa[fu] = fv;
				}
			}
		}
		cnt = 0;
		for (auto x : v)
			cnt += (fa[x] == x);
		if (cnt > 2) continue;
		for (int i = 1; i <= n; i++) dis[i] = 1e9;
		for (auto x : v)
			dfs(x, 0, 0);
//		for (int i = 1; i <= n; i++) cout << dis[i] << " ";cout << endl;
		int ma = 0;
		for (int i = 1; i <= n; i++) ma = max(ma, dis[i]);
		ans = min(ans, ma);
	}
	cout << ans << endl;
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _;
	cin >> _ >> _;
	while (_--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

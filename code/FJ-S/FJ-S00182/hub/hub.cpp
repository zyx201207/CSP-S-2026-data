#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2000010;
int n, k, ans = 0x3f3f3f3f, vis[N], fa[N][24], dep[N], Fa[N];
int head[N], to[N], nx[N], idx = 1;

void Init() {
	memset(dep, 0, sizeof dep);
	memset(fa, 0, sizeof fa);
	memset(head, 0, sizeof head), idx = 1;
	ans = 0x3f3f3f3f;
}

void add(int u, int v) {
	idx++, to[idx] = v, nx[idx] = head[u], head[u] = idx;
	idx++, to[idx] = u, nx[idx] = head[v], head[v] = idx;
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 23; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 23; i >= 0; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int solve() {
	int Res = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int res = 0x3f3f3f3f;
			for (int j = 1; j <= n; j++)
				if (vis[j])
					res = min(res, dist(i, j));
			Res = max(res, Res);
		}
	return Res;
}

int find(int x) {
	if (Fa[x] == x) return x;
	return Fa[x] = find(Fa[x]);
}

bool check() {
	for (int i = 1; i <= n; i++) Fa[i] = i;
	for (int i = 1; i <= n; i++)
		if (vis[i])
			for (int j = head[i]; j; j = nx[j]) {
				int y = to[j];
				if (!vis[y]) continue;
				int rx = find(i), ry = find(y);
				if (Fa[rx] != Fa[ry]) Fa[rx] = ry;
			}
	unordered_map<int, bool> mp;
	for (int i = 1; i <= n; i++)
		if (vis[i]) mp[find(i)] = 1;
	return mp.size() <= 2;
}

void dfs(int x, int cnt) {
	if (x > n) {
		if (cnt != k) return;
		if (!check()) return;
		ans = min(ans, solve());
		return;
	}
	if (cnt != k)
		vis[x] = 1,
		dfs(x + 1, cnt + 1);
	vis[x] = 0;
	dfs(x + 1, cnt);
}

void Dfs(int x, int F) {
	dep[x] = dep[F] + 1, fa[x][0] = F;
	for (int i = 1; i <= 23; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (int i = head[x]; i; i = nx[i]) {
		int y = to[i];
		if (y == F) continue;
		Dfs(y, x);
	}
}

void Main() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		add(u, v);
	}
	Dfs(1, 0);
	dfs(1, 0);
	cout << ans << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _,  T; cin >> _ >> T;
	while (T--) {
		Init();
		Main();
	}
	return 0;
}

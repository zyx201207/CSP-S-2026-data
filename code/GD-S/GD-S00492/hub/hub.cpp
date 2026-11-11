#include <bits/stdc++.h>
namespace GD00492 {
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef pair<int, int> pii;
mt19937 rnd(time(0));
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rnd);
}
const int maxn(1e6 + 9), maxl(__lg(maxn) + 2);
int n, k, ans;
basic_string<int> G[maxn];
int f[maxn][2], dep[maxn], hig[maxn];
int k1, k2;
bool tou[maxn];
int dfn[maxn], dfntot, st[maxl][maxn];
int Dep[maxn];
int anD;
void dfs0(int u, int fa) {
	st[0][dfn[u] = ++dfntot] = fa,
	Dep[u] = Dep[fa] + 1,
	hig[u] = 0;
	for (int v : G[u]) if (v ^ fa) {
		dfs0(v, u);
		anD = max(anD, hig[u] + hig[v] + 2);
		hig[u] = max(hig[u], hig[v]);
	}
	++hig[u];
}
int lca(int u, int v) {
	if (u == v) return u;
	u = dfn[u], v = dfn[v];
	if (u > v) swap(u, v);
	int l = __lg(v - u); ++u;
	return st[l][dfn[st[l][u]] < dfn[st[l][v - (1 << l) + 1]] ? u : v - (1 << l) + 1];
}
int dis(int u, int v) { // edge
	return Dep[u] + Dep[v] - (Dep[lca(u, v)] << 1);
}
void dfs1(int u, int fa) {
	if (u == k1 || u == k2) {
		tou[u] = 1;
		return;
	}
	dep[u] = dep[fa] + 1, hig[u] = 0;
	for (int v : G[u]) if (v ^ fa) {
		dfs1(v, u),
		hig[u] = max(hig[u], hig[v]);
	}
	++hig[u];
}
priority_queue<pii> lis;
int sol2() {
	dep[k1] = dep[k2] = 0;
	memset(tou + 1, 0, sizeof(tou[0]) * n);
	tou[k1] = tou[k2] = 1;
	for (int v : G[k1]) if (!tou[v]) {
		dfs1(v, k1);
		if (!tou[v]) lis.emplace(hig[v], v);
	}
	for (int v : G[k2]) if (!tou[v]) {
		dfs1(v, k2);
		if (!tou[v]) lis.emplace(hig[v], v);
	}
	for (int _ = 2, u; _ < k && !lis.empty(); ++_) {
		u = lis.top().se, lis.pop();
		tou[u] = 1;
		for (int v : G[u])
			if (!tou[v])
				lis.emplace(hig[v], v);
	}
	int ans = 0;
	while (!lis.empty()) ans = max(ans, lis.top().fi), lis.pop();
	return ans;
}
bool check(int d) {
	for (int _ = 100; _--; ) {
		k1 = rand(1, n), k2 = 0;
		int be = d * 2, le;
		for (int i = 1; i <= n; ++i) if (i ^ k1) {
			le = dis(k1, i);
			if (le == (d << 1 | 1))
				k2 = i, be = le;
			else if (le == be && (!k2 || rand(0, 1))) k2 = i;
		}
		if (!k2) return 1;
		if (sol2() <= d) return 1;
	}
	return 0;
}
void init() {
	for (int i = 1; i <= n; ++i)
		G[i].clear();
	dfntot = 0;
}
void mian() {
	init();
	cin >> n >> k;
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v,
		G[u] += v, G[v] += u;
	if (k == n)
		return cout << "0\n", void();
	anD = 0;
	dfs0(1, 0);
	for (int l = 1; l < maxl; ++l)
	for (int i = 1, j = 1 + (1 << l - 1), ir = n - (1 << l) + 1; i <= ir; ++i, ++j)
		st[l][i] = st[l - 1][dfn[st[l - 1][i]] < dfn[st[l - 1][j]] ? i : j];
	ans = min(anD + 3 >> 1, (n - k + 2) / 3);
	int l = 1, r = ans - 1, mid;
	while (l <= r) {
		mid = l + r >> 1;
		if (check(mid))
			r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << '\n';
}
} using namespace GD00492;
int main() {
#ifdef LOCAL00492
	freopen("hub3.in", "r", stdin);
#else
	freopen("hub.in", "r", stdin),
	freopen("hub.out", "w", stdout);
#endif
	ios::sync_with_stdio(false),
	cin.tie(nullptr), cout.tie(nullptr);
	int c, T = 1;
	cin >> c >> T;
	while (T--) mian();
	return 0;
}


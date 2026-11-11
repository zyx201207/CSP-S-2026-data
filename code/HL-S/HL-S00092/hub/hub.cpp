#include <bits/stdc++.h>
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x);fout(x);
using namespace std;
constexpr int N = 1e6 + 5;
int c, t, n, m, l, r, mid, dep[N], dis1[N], dis2[N], idx, dfn[N], re[N], siz[N], fa[N], fas[N], maxi, rt;
bitset <N> vis;
vector <int> e[N];
void dfs1(int x, int z) {
	if (dep[x] > dep[maxi]) maxi = x;
	for (int y : e[x]) if (y != z) fa[y] = x, dep[y] = dep[x] + 1, dfs1(y, x);
}
void dfs3(int x, int z) {
	dis1[x] = dis2[x] = siz[x] = 0;
	dfn[x] = ++idx, re[idx] = x;
	for (int y : e[x]) if (y != z) {
		fa[y] = x, dfs3(y, x);
		siz[x] += siz[y];
		if (dis1[y] + 1 >= dis1[x]) dis2[x] = dis1[x], dis1[x] = dis1[y] + 1;
		else if (dis1[y] + 1 >= dis2[x]) dis2[x] = dis1[y] + 1;
	}
	siz[x] += (dis1[x] >= mid);
}
bool check() {
	int rt = fas[mid];
	idx = 0, dfs3(rt, 0);
	if (siz[rt] <= m) return true;
	int len = siz[rt] - m;
	for (int i = 1; i <= n; ++i) vis[i] = false;
	vis[rt] = true;
	for (int i = n; i > 1; --i) {
		int x = re[i];
		if (vis[x] || dis1[x] <= mid || dis2[x] >= mid) continue;
		int cnt = 0;
		vector <pair <int, int> > v;
		while(!vis[x] && dis1[x] > mid && dis2[x] < mid) {
			vis[x] = true, ++cnt;
			int L = max(1, cnt + mid - dis2[x] - len + 1);
			int R = cnt - mid + dis2[x];
			if (L <= R) v.emplace_back(L, R);
			x = fa[x];
		}
		if (cnt < len) continue;
		sort(v.begin(), v.end());
		int nowR = 0;
		for (auto j : v) {
			if (j.first > cnt - len + 1) break;
			if (j.first > nowR + 1) return true;
			nowR = max(nowR, j.second);
		}
		if (cnt - len + 1 > nowR) return true;
	}
	return false;
}
signed main() {
	file(hub);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c >> t;
	while(t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 1, x, y; i < n; ++i) cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
		if (n == m) { cout << 0 << '\n'; continue; }
		maxi = 0, dep[1] = 1, dfs1(1, 0);
		rt = maxi, maxi = 0, dep[rt] = 1, dfs1(rt, 0);
		fas[0] = maxi;
		for (int i = 1; i < dep[maxi]; ++i) fas[i] = fa[fas[i - 1]];
		l = 0, r = dep[maxi] - 1;
		while(l <= r) {
			mid = (l + r) >> 1;
			if (check()) r = mid - 1;
			else l = mid + 1;
		}
		cout << l << '\n';
	}
}


#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, t, n, k, sz[1000006], h[1000006], fa[1000006], bfa[21][1000006], dep[1000006], dfn[1000006], dft, tot[1000006];
vector<int> edges[1000006];

void dfs(int i) {
	sz[i] = 1;
	h[i] = 0;
	dfn[i] = ++dft;
	bfa[0][i] = fa[i];
	for (int j = 1; j <= 20; ++j) bfa[j][i] = bfa[j - 1][bfa[j - 1][i]];
	for (auto j : edges[i]) {
		if (j == fa[i]) continue;
		fa[j] = i;
		dep[j] = dep[i] + 1;
		dfs(j);
		sz[i] += sz[j];
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y];
	for (int l = 0; t; t >>= 1, ++l) {
		if (t & 1) x = bfa[l][x];
	}
	if (x == y) return x;
	for (int l = 20; ~l; --l) {
		if (bfa[l][x] != bfa[l][y]) {
			x = bfa[l][x];
			y = bfa[l][y];
		}
	}
	return fa[x];
}
int get_dst(int x, int y) {
	return dep[x] +dep[y] - dep[lca(x, y)] * 2;
}

int dfa[12];

int get_fa(int i) {
	if (i == dfa[i]) return i;
	return dfa[i] = get_fa(dfa[i]);
}

int get_ans(int x, int y) {
	int ans = 0;
	for (int z = 1; z <= n; ++z) {
		ans = max({ans, min(get_dst(x, z), get_dst(z, y))});
	}
	return ans;
}

pair<int, int> find_far(int x, int fm = -1) {
	pair<int, int> res = {0, x};
	for (auto j : edges[x]) {
		if (j == fm) continue;
		auto tmp = find_far(j, x); tmp.first++;
		res = max(res, tmp);
	}
	return res;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) edges[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dft = 0;
	dfs(1);
	if (k == n) {
		cout << "0\n";
		return;
	} else if (n <= 10 && 0) {
		int fans = 1ll << 60;
		for (int f = 0; f < (1 << n); ++f) {
			if (__builtin_popcount(f) != k) continue;
			for (int i = 1; i <= n; ++i) dfa[i] = i;
			for (int i = 2; i <= n; ++i) {
				if (((f >> (i - 1)) & 1) && ((f>>(fa[i] - 1))&1)) {
					dfa[get_fa(i)] = get_fa(fa[i]);
				}
			}
			int ct = 0;
			for (int i = 1; i <= n; ++i) {
				if ((f >> (i - 1)) & 1)
				ct += (dfa[i] == i);
			}
			if (ct <= 2) {
				int ans = 0;
				for (int j = 1; j <= n; ++j) {
					int mdst = 1ll << 60;
					for (int k = 1; k <= n; ++k) {
						if ((f >> (k - 1)) & 1) mdst = min(mdst, get_dst(j, k));
					}
					ans = max(ans, mdst);
				}
				fans = min(fans, ans);
			}
		}
		cout << fans << "\n";
	} else if (k <= 2 && 0) {
		pair<int, int> x = find_far(1);
		pair<int, int> y = find_far(x.second);
		vector<int> lja, ljb;
		int u = x.second, v = y.second;
		int l = lca(u, v);
		while (u != l) {
			lja.push_back(u);
			u = fa[u];
		}
		lja.push_back(l);
		while (v != l) {
			ljb.push_back(v);
			v = fa[v];
		}
		reverse(ljb.begin(), ljb.end());
		for (auto i : ljb) lja.push_back(i);
		int ita = lja.size() / 4, itb = ita * 3;
		int ans = 1ll << 60;
		cout << x.second << " : " << y.second << "\n";
		cout << lja.size() << "!\n";
		for (int dt = -3; dt <= 3; ++dt) {
			for (int dt2 = -3; dt2 <= 3; ++dt2) {
				int ra = ita + dt, rb = itb + dt2;
				if (ra >= 0 && ra < lja.size() && rb >= 0 && rb < lja.size()) {
					ans = min(ans, get_ans(lja[ra], lja[rb]));
				}
			}
		}
		cout << ans << "\n";
	}
}

signed main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
// 这真的是题吗 

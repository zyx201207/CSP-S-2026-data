#include <bits/stdc++.h>
// #define int long long
// #define lson (id << 1)
// #define rson (id << 1 | 1)
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

 constexpr int N = 1005;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;

int n, k;
vector<int> G[N];
bool c[N]; int dep[N];

int dfs(int u, int fa, int rt) {
	dep[u] = dep[fa] + 1;
	int res = 1e9;
	if (c[u]) res = dep[u] - dep[rt];
	for (auto& v : G[u]) {
		if (v == fa) continue;
		res = min(res, dfs(v, u, rt));
	}
	return res;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v), G[v].push_back(u);
	}
	int ans = 1e9;
	for (int i = 0; i < (1 << n); i ++) {
		if (__builtin_popcount(i) > k) continue;
		for (int j = 1; j <= n; j ++) {
			c[i] = (i >> (j - 1)) & 1;
		}
		int mx = 0;
		for (int j = 1; j <= n; j ++) {
			mx = max(mx, dfs(j, 0, j));
		}
		ans = min(ans, mx);
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i ++) G[i].clear();
}

signed main()
{
     freopen("hub.in", "r", stdin);
     freopen("hub.out", "w", stdout);
     ios::sync_with_stdio(0), cin.tie(0);
    int c, T; cin >> c >> T;
    while (T --) solve();
    return 0;
}

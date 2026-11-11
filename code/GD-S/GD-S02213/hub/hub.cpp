#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;

using PII = pair<int, int>;
using PLL = pair<ll, ll>;

#define rep(i, j, k) for (int (i) = (j); (i) < (k); (i)++)
#define __rrep(i, j, k) for (int (i) = (j); (i) <= (k); (i)++)

constexpr ll inf = (1ll << 62);
constexpr int N = 5e5 + 10;

template <typename T> void chkmax(T& a, T b) { a = max(a, b); }
template <typename T> void chkmin(T& a, T b) { a = min(a, b); }

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int ans = n;
	rep(mask, 0, 1 << n) {
		if (__builtin_popcount(mask) != k) continue;
		vector<int> fa(n);
		vector<bool> flag(n);
		iota(fa.begin(), fa.end(), 0);
		rep(i, 0, n) {
			if ((1 << i) & mask) {
				flag[i] = true;
			}
		}
		
		function<int(int)> find = [&](int x) {
			return fa[x] == x ? x : fa[x] = find(fa[x]);
		};
		
		function<void(int, int)> merge = [&](int a, int b) {
			int x = find(a), y = find(b);
			fa[x] = y;	
		};
		
		int cnt = k;
		rep(i, 0, n) {
			if (!flag[i]) continue;
			for (auto j : adj[i]) {
				if (!flag[j]) continue;
				if (find(i) != find(j)) {
					cnt--;
					merge(i, j);
				}
			}
		}
		if (cnt > 2) continue;
		queue<int> q;
		vector<int> d(n), vis(n);
		rep(i, 0, n) {
			if (flag[i]) {
				q.push(i);
				vis[i] = true;
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v : adj[u]) {
				if (vis[v]) continue;
				d[v] = d[u] + 1;
				vis[v] = true;
				q.push(v);
			}
		}
		int maxn = *max_element(d.begin(), d.end());
		chkmin(ans, maxn);
	}
	cout << ans << "\n";
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, t = 1;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}

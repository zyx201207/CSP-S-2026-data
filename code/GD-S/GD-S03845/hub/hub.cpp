#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cid, tt; cin >> cid >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v;
			u--, v--;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		
		int ans = 0x3f3f3f3f;

		for (int msk = 0; msk < (1 << n); msk++) {
			if (__builtin_popcount(msk) != k) continue;

			int ksm = (~msk) & ((1 << n) - 1);
			
			int mx = 0;
			
			int vis = 0;
			auto bfs = [&](int s) {
				queue<int> q;
				q.emplace(s);
				vis |= 1 << s;
				while (!q.empty()) {
					int u = q.front(); q.pop();
					for (auto v : g[u]) {
						if (vis >> v & 1) continue;
						if (!(msk >> v & 1)) continue;
						vis |= 1 << v;
						q.emplace(v);
					}
				}
			};

			int cnt = 0;
			for (int i = msk; i; i -= i & -i) {
				int k = __builtin_ctz(i);
				if (vis >> k & 1) continue;
				bfs(k); cnt++;
			}
			
			if (cnt > 2) continue;
			
			for (int j = ksm; j; j -= j & -j) {
				int k = __builtin_ctz(j);
				mx = max(mx, [&]() {
					queue<pair<int, int>> q;
					int vis = 0;
					q.emplace(k, 0);
					vis |= 1 << k;
					while (!q.empty()) {
						int u = q.front().first, step = q.front().second; q.pop();
						for (auto v : g[u]) {
							if (vis >> v & 1) continue;
							if (msk >> v & 1) return step + 1;
							vis |= 1 << v;
							q.emplace(v, step + 1);
						}
					}
					return 0x3f3f3f3f;
				} ());
			}
			ans = min(ans, mx);
		}
		
		cout << ans << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace Code {
	constexpr int N = 1e3 + 5;

	int c, t;
	int n, k;

	int dis[N][N];
	int mx[N];

	vector < int > G[N];

	void DFS(int pos, int father, int start) {
		for (auto i : G[pos]) {
			dis[start][i] = dis[start][pos] + 1;
			mx[start] = max(mx[start], dis[start][i]);
			DFS(i, pos, start);
		}
	}

	void main() {
		cin >> c >> t;
	
		while (t --) {
			for (int i = 1; i < N; ++ i) G[i].clear();
			memset(dis, 0, sizeof (dis));
			memset(mx, 0, sizeof (mx));

			cin >> n >> k;

			for (int i = 1; i < n; ++ i) {
				int u, v;
				cin >> u >> v;

				G[u].emplace_back(v);
				G[v].emplace_back(u);
			}

			for (int i = 1; i <= n; ++ i) DFS(i, 0, i);

			int ans = INT_MAX;
			for (int i = 1; i <= n; ++ i) {
				for (int j = 1; j <= n; ++ j) {
					if (i == j) continue;

					ans = min({ans, mx[i], mx[j]});
				}
			}

			cout << ans << '\n';
		}
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Code::main();

	return 0;
}

/*
++ rp
*/
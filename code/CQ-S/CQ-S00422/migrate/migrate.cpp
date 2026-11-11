#include <bits/stdc++.h>
#define int long long

using namespace std;

int c, t;

namespace Force {
	constexpr int N = 9 + 5;
	constexpr int inf = LLONG_MAX;

	int n, d;
	int p[N];

	int mn[N][N], cnt[N][N];

	int src;
	void DFS(int cur, int len) {
		if (len) {
			if (mn[src][cur] > len) {
				mn[src][cur] = len;
				cnt[src][cur] = 1;
			} else if (mn[src][cur] == len)
				++ cnt[src][cur];
		}

		for (int i = cur + 1; i <= n; ++ i) {
			if (p[i] - p[cur] <= d)
				DFS(i, len + 1);
		}
	}

	void main() {
		while (t --) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++ i)
				cin >> p[i];
			
			for (int i = 1; i <= n; ++ i) {
				for (int j = 1; j <= n; ++ j) {
					mn[i][j] = inf;
					cnt[i][j] = 0;
				}
			}
			
			for (int i = 1; i <= n; ++ i) {
				src = i;
				DFS(i, 0);
			}

			int ans = 0;
			for (int i = 1; i <= n; ++ i)
				for (int j = i + 1; j <= n; ++ j)
					if (cnt[i][j] == 2)
						++ ans;
			
			cout << ans << '\n';
		}
	}
}

namespace ForceA {
	constexpr int N = 2e6 + 5;

	int n, d;
	int p[N];

	void main() {
		while (t --) {
			cin >> n >> d;
			for (int i = 1; i <= n; ++ i)
				cin >> p[i];
			
			if (n == 1) {
				cout << 0 << '\n';
				continue;
			}

			int C = p[2] - p[1];
			int v = -1;
			for (int i = 2; 2 * i - 1 < n; ++ i) {
				if ((i + 1) * C > d && i * C <= d) {
					v = 2 * i - 1;
					break;
				}
			}

			if (v != -1) cout << n - v << '\n';
			else cout << 0 << '\n';
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> c >> t;

	if (c == 1 || c == 2) Force::main();
	else if (c == 11 || c == 12) ForceA::main();

	return 0;
}
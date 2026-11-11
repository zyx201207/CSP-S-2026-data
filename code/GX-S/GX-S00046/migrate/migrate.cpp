#include <bits/stdc++.h>
// #ifndef node
#define int long long
// #endif
using namespace std;

// struct Node {
// 	int cnt;
// 	int lnd;

// 	bool operator<(node other) {
// 		return lnd < other.lnd;
// 	}
// }

int c, t, n, d, ans, x[2000001], g[2000001], f[2000001];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(x, 0, sizeof(x));
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		f[1] = 1;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= d; j++) {
				if (i - j > 0 && x[i] - x[i - j] > 0)
					f[i] = f[i - j] + 1;
			}
		}
		for (int i = 1; i <= n; i++) if (f[i] == 2) ans++;
		cout << ans / 2 << endl;
	}
	return 0;
}
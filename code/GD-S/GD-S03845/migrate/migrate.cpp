#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cid, tt;
	cin >> cid >> tt;
	while (tt--) {
		int n; long long d; cin >> n >> d;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		
		long long ans = 0;
		
		for (int i = 0; i < n; i++) {
			vector<int> f(n, 0x3f3f3f3f); vector<long long> g(n);
			f[i] = 0, g[i] = 1;
			for (int j = i + 1; j < n; j++) {
				for (int k = i; k < j; k++)
					if (abs(a[k] - a[j]) <= d) {
						if (f[k] + 1 < f[j]) {
							f[j] = f[k] + 1;
							g[j] = g[k];
						} else if (f[k] + 1 == f[j]) {
							g[j] += g[k];
						}
					}
//				if (g[j] == 2) debug("(%d, %d)\n", i, j);
				ans += g[j] == 2;
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}

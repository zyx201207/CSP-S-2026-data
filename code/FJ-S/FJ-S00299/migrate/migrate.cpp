#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 10;
ll c, t, n, d, x[N], ans;
ll f[N][N], s[N][N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%lld%lld", &c, &t);
	while (t--) {
		ans = 0;
		memset(f, 0x3f, sizeof(f));
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		
		for (int i = 1; i <= n; i++) {
			f[i][i] = 0;
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					f[i][j] = f[j][i] = x[j] - x[i];
				}
			}
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = 1 + 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) {
						continue;
					}
					if (f[i][j] > f[i][k] + f[k][j]) {
						f[i][j] = f[j][i] = f[i][k] + f[k][j];
						s[i][j] = s[j][i] = 1;
					} else if (f[i][j] == f[i][k] + f[k][j]) {
						s[i][j]++;
						s[j][i]++;
					}
				}
			}
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (s[i][j] == 2) {
					ans++;
				}
			}
		}
		
		printf("%lld\n", ans);
	}
	return 0;
} 

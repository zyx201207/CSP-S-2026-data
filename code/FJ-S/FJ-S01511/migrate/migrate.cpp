#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;

int c, t, n;
ll d, a[N], dp[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w" ,stdout);
	scanf("%d %d", &c, &t);
	
	while (t--) {
		int ans = 0;
		scanf("%d %lld", &n, &d);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
		}
		for (int i = 1; i <= n; ++i) {
			dp[i] = 1;
			int l = i, nl;
			while (l <= n) {
				//printf("%d\n", l);
				nl = n + 1;
				for (int j = n; j >= l; --j) {
					int tmp = lower_bound(a + l, a + j, a[j] - d) - a;
					ll sum = 0;
					for (int k = tmp; k < j; ++k) {
						sum += dp[k];
					}
					if (sum > 0) {
						nl = j;
						if (sum == 2 && dp[j] == 0) {
							++ans;
						}
					}
					dp[j] = sum;
				}
				l = nl;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}


//GZ-S00396 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int C, T, n;
ll d, a[N], dp[N], sum, mi, l, r;
void dfs (int x, int y, ll z) {
	for (int i = x + 1; a[i] - a[x] <= d && i <= y; i++) {
		if (i == y) {
			if (!r || z < r) r = z, l = 1;
			else if (r == z) l++;
			return ;
		}else dfs(i, y, z + 1);
	}
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d", &C, &T);
	while (T--) {
		sum = 0;
		scanf ("%d%d", &n, &d);
		for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
		if (n <= 500) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d) continue;
					l = r = 0, dfs (i, j, 0);
					if (l == 2) sum++;
				}
			}
		}else {
			for (int i = 1; i < n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d) dp[j] = 1;
					else {
						mi = LONG_MAX;
						for (int k = j - 1; k > i && a[j] - a[k] <= d; k--) {
							if (dp[k] < mi) mi = dp[k], dp[j] = dp[k];
							else if (dp[k] == mi) dp[j] += dp[k];
						}
						if (dp[j] == 2) sum++;
					}
				}
			}
		}
		printf ("%lld\n", sum);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}

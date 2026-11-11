#include <cstdio>
#include <algorithm>
#define int long long

const int N = 2e6 + 1;
const int N1 = 5001;
const int INF = 2e18;

int ipt, tests;
int n, d, ans, pos[N], step[N];
int costs[N1][N1], paths[N1][N1];

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/

signed main() {
	std::freopen("migrate.in", "r", stdin);
	std::freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &ipt, &tests);
	while (tests--) {
		scanf("%lld %lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", &pos[i]); ans = 0;
		for (int i = 1; i <= n; i++) step[i] = std::upper_bound(pos + 1, pos + n + 1, pos[i] + d) - pos - 1;
		for (int i = 1; i <= n; i++) for (int j = i - 1; j >= 1; j--) {
			if (step[j] == j) costs[j][i] = INF;
			else costs[j][i] = costs[step[j]][i] + 1;
		} 
//		for (int i = 1; i <= n; i++) printf("%lld ", step[i]); putchar('\n');
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				printf("%lld ", costs[i][j]);
//			} putchar('\n');
//		}
		for (int i = 1; i <= n; i++) paths[i][i] = 1;
		for (int len = 2; len <= n; len++) for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1; paths[l][r] = 0;
			if (pos[l] + d >= pos[r]) paths[l][r] = 1;
			else for (int p = l + 1; p < r; p++) {
				int p1 = costs[l][p] + costs[p][r] == costs[l][r];
				int p2 = paths[l][p] * paths[p][r];
				paths[l][r] += p1 * p2 - ((paths[l][p] == 1) ? (pos[l] + d < pos[p]) : paths[l][p]);
				// printf("DEBUG1: %lld %lld %lld %lld %lld %lld\n", l, r, p, p1, p2, paths[l][r]);
			} // printf("DEBUG2: %lld %lld %lld\n", l, r, paths[l][r]);
			ans += (paths[l][r] == 2);
		} printf("%lld\n", ans);
	}
	return 0;
}


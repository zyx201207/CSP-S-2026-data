// GZ-S00114 安顺市第二高级中学 程泊郡
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5010;
const ll INF = 1000000000000000000;

int c, T, n;
ll d, x[N], f[N][N], g[N][N];

void solve() {
	ll sd = 0;
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = INF;
			g[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
		g[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			res[j] = 0;
//		}
//		res[0] = 1;
		for (int j = i + 1; j <= n; j++) {
			int ans = j, l = i, r = j - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (x[j] - d <= x[mid]) {
					ans = mid;
					r = mid - 1;
				} else l = mid + 1;
			}
//			printf("%d:%d\n", i, ans);
			if (ans == j) continue;
			ll val = INF;
//			for (int z = ans; z < j; z++) printf("%lld ", f[i][z]);
//			printf("\n");
			for (int z = ans; z < j; z++) val = min(val, f[i][z]);
			f[i][j] = val + 1;
//			printf("ts:  %lld\n", val);
//			res[f[i][j]]++;
			for (int z = ans; z < j; z++) if (f[i][z] == f[i][j] - 1) g[i][j] += g[i][z];
			if (g[i][j] == 2) sd++;
		}
//		printf("%d: ", i);
//		printf("[");
//		for (int j = i + 1; j <= n; j++) {
//			printf("%d ", f[i][j]);
//		}
//		printf("]");
//		for (int j = i + 1; j <= n; j++) {
//			printf("%d ", g[i][j]);
//		}
//		printf("\n");
	}
	printf("%lld\n", sd);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) solve();
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

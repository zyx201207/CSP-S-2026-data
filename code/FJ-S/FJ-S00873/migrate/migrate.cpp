#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
#define int long long
int c, t;
int n, d;
int x[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate4.in", "r", stdin);
//	freopen("migrates.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		if (c >= 11 && c <= 12) {
			int tt = d / (x[2] - x[1]);
			if (tt > 1)  {
				printf("%lld\n", max(0LL, n - (2 * tt - 1)));
			}
			else {
				printf("0\n");
			}
		}
	}
	return 0;
}

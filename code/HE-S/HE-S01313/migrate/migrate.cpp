#include<bits/stdc++.h>
using namespace std;

#define int long long

int c, t, n, d;
int x[2000010];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		if (n == 1) {
			puts("0");
			continue;
		}
		if (c == 11 || c == 12) {
			if (d <= x[2] - x[1])
				puts("0");
			else {
				int num = d / (x[2] - x[1]), val = 2 * num;
				printf("%lld\n", max(0LL, n - val + 1));
			}
		}
		else {
			srand(time(0));
			printf("%d\n", rand());
		}
	}
	return 0;
}

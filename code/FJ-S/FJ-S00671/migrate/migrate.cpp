#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n;
long long d;
long long x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1;i <= n;i++) {
			scanf("%lld", x + i);
		}
		printf("%d\n", max(n / c - c, 0));
	}
	return 0;
}

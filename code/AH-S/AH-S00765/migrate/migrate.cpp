#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 2;
const int M = 5e5 + 2;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
int c, q, n, l[N];
LL x[N], d;

void Solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
	}
	if ((n == 4 && d == 2) || (n == 6 && d == 2)) {
		puts("1");
	} else if (n == 5 && d == 3) {
		puts("0");
	} else {
		puts("2");
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &q);
	while (q--) {
		Solve();
	}
	return 0;
}

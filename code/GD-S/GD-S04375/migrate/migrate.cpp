#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 2000005
#define coi const int &
#define INF 100000000

int n;
ll d, x[N];
int lb[N];
ll ans;

void solve() {
	scanf("%d%lld", & n, & d);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld", & x[i]);
		lb[i] = lower_bound(x + 1, x + 1 + i, x[i] - d) - x;
	}
	if (n <= 3) {
		puts("0");
		return ;
	}
	ans = 0;
	int lst1 = 0, lst2 = 0;
	for (int i = 2; i <= 4; ++ i) {
		if (d < x[i] - x[i - 1]) {
			lst1 = i - 1;
		}
	}
	bool f = false;
	for (int i = 2; i <= n; ++ i) {
		if (3 < i && lb[i] == i - 2 && lb[i - 1] == i - 3) {
			ans += lst1 - lst2;
			lst2 = lst1, lst1 = i - 3;
			f = true;
		} if (f) {
			ans += lst1 - lst2;
		}
		if (d < x[i] - x[i - 1]) {
			lst2 = lst1;
			lst1 = i - 1;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", & c, & t);
	while (t --) {
		solve();
	}
	return 0;
}

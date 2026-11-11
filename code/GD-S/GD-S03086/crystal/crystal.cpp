#include <cstdio>
#include <algorithm>
#define int long long

inline int max(int x, int y) { return x > y ? x : y; }

const int N = 6e5 + 1;

int n, m, ans, a[N], dif[N], predif[N], prepredif[N];

inline bool check(int i, int k) {
	if (k == 1) return 1;
	int frt = (k - 1) * predif[i - 1];
	int bck = prepredif[i - 2] - prepredif[max(0, i - k - 1)];
	int val = frt - bck;
	return val <= m;
}

/*
5 5
1 2 4 8 9

3
*/

signed main() {
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) dif[i] = a[i + 1] - a[i];
	for (int i = 1; i <= n; i++) predif[i] = predif[i - 1] + dif[i];
	for (int i = 1; i <= n; i++) prepredif[i] = prepredif[i - 1] + predif[i];
//	for (int i = 1; i <= n; i++) printf("%d ", dif[i]); putchar('\n');
//	for (int i = 1; i <= n; i++) printf("%d ", predif[i]); putchar('\n');
//	for (int i = 1; i <= n; i++) printf("%d ", prepredif[i]); putchar('\n');
//	check(3, 3);
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, mid, k;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(i, mid)) k = mid, l = mid + 1;
			else r = mid - 1;
		} // printf("%lld %lld\n", i, k);
		ans = max(ans, k);
	} printf("%lld", ans);
	return 0;
}


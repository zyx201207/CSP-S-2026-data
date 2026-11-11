#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10, MIN = 1e12 + 10;
long long n, m, a[MAX];
bool check(long long x) {
	long long mi = MIN;
	for (int i = x; i <= n; ++i) {
		long long sum = 0;
		for (int j = i - x + 1; j < x; ++j) {
			sum += a[i] - a[j];
		}
		mi = min(mi, sum);
	}
	return mi <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	long long c = a[2] - a[1];
	bool f = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] - a[i - 1] != c) f = 0;
	}
	if (f) {
		double solve = (sqrt(c * c + 8 * m * c) - c) / 2;
		long long a1 = solve / c + 1;
		long long print = min(a1, n);
		cout << print;
	} else {
		long long l = 1, r = n, ans;
		while(l <= r) {
			long long mid = (l + r) / 2;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}
		cout << ans;
	}
	return 0;
}

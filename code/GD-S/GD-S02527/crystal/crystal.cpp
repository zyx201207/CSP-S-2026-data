#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
int n;
long long m;
bool cmp(long long x, long long y) {
	return x < y;
}
bool check(int mid) {
	for (int i = 1; i + mid - 1 <= n; i++) {
		long long sum = 0;
		int idx = i + mid - 1;
		for (int j = i; j <= idx; j++) {
			sum += (a[idx] - a[j]);
		}
		if (sum <= m) {
			return true;
		}
	}  
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d", ans);
	return 0;
}

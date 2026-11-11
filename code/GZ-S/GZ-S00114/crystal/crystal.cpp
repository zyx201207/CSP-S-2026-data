// GZ-S00114 安顺市第二高级中学 程泊郡
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500010;

int n;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int res = i, l = 1, r = i - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (1LL * a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m) {
				res = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf("%d", ans);
	return 0;
}

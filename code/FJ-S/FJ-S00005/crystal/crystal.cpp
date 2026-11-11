#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans = 1;
long long m, a[N], sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m)
				res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf("%d", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll m, a[500010], pre[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int L = 0, R = i;
		while (L + 1 < R) {
			int mid = (L + R) / 2;
			if (1ll * (i - mid) * a[i] - pre[i - 1] + pre[mid - 1] <= m) {
				R = mid;
			} else {
				L = mid;
			}
		}
		ans = max(ans, i - R + 1);
	}
	printf("%d\n", ans);
	return 0;
}


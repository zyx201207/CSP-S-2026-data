#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501000;
int n;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int L = 1, R = i;
		while (L < R) {
			int mid = (L + R) / 2;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) R = mid;
			else L = mid + 1;
		}
		ans = max(ans, i - L + 1);
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
int n, ans;
ll m, a[N], s[N];
ll sum(int l, int r) {
	return s[r] - s[l - 1];
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - sum(mid, i) <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf("%d\n", ans);
	return 0;
}

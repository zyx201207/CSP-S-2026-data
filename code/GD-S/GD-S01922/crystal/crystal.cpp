#include <bits/stdc++.h>
using namespace std;
int n;
long long a[501000];
long long m;
long long s[501000];
int c[501000], ans = 0, b[5010], t = 0;
bool cmp(const int &x, const int &y) {
	return x < y;
}
inline void solve(int x) {
	if (x == n + 1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += c[i];
		if (cnt != m) {
			return;
		}
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++)
			b[a[i] + c[i] + 100]++;
		for (int i = 1; i <= n; i++)
			ans = max(b[a[i] + c[i] + 100], ans);
		return;
	}
	for (int i = (x == n?m - t:0); i <= m - t; i++) {
		t += i;
		c[x] = i;
		solve(x + 1);
		t -= i;
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	if (n <= 5) {
		solve(1);
		printf("%d\n", ans);
		return 0;
	}
	if (n <= 5000) {
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			long long sum = 0;
			for (int j = i; j; j--) {
				sum += a[j];
				if ((i - j + 1) * a[i] - sum <= m)
					ans = max(ans, i - j + 1);
				else
					break;
			}
		}
		printf("%d", ans);
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (mid * a[i] - (s[i - 1] - s[i - mid - 1]) <= m)
				l = mid;
			else {
				r = mid;
			}
		}
		ans = max(ans, l + 1);
	}
	printf("%d\n", ans);
	return 0;
}

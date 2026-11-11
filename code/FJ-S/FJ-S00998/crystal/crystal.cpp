#include <bits/stdc++.h>
#define int long long

using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1; c = getchar();
	} while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, m, sum, a[500001], ans, s = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int add = (a[i] - a[i - 1]) * (i - s);
		if (sum + add > m || sum + add < sum)
			ans = max(ans, i - s);
		while (s < i && (sum + add > m || sum + add < sum))
			sum -= a[i - 1] - a[s], add -= a[i] - a[i - 1], s++;
		sum += add;
	} ans = max(ans, n - s + 1);
	printf("%lld", ans);
	return 0;
}

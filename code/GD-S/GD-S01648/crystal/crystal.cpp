#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k; 
}

const int N = 5e5 + 7;

long long n, m, a[N], s[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i ++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i];
	long long cnt = 0;
	for (int i = 1, l = 0; i <= n; i ++) {
		while (l <= i && a[i] * (i - l) - (s[i] - s[l]) > m)
			l ++;
		cnt = max(cnt, 1ll * i - l);
	} 
	cout << cnt << '\n';
	return 0;
}

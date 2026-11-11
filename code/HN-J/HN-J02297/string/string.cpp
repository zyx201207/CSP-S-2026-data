// lichenxi108.rp = inf, JCer.rp = -inf;
// 也许这是最后一战了。I won't AFO.
// 我该在哪里停留？我问我自己。

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
long long a[N], b[N], d[N], ans, len;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[i] = b[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		d[i] = d[i + 1] + a[i];
	}
	len = b[n];
	int l = 1, r = n;
	for (long long i = 0; ; ) {
		if (c[l] != c[r]) ans += min(b[l], d[r]) - i;
		i = min(b[l], d[r]);
		if (i == b[l]) l++;
		if (i == d[r]) r--;
		if (l >= r) break;
	}
	
	cout << ans;
	return 0;
} 

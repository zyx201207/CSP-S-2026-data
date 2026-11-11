#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[500010], b[500010], c[500010];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n - 1; i >= 1; i--) {
		b[i] = a[i + 1] - a[i];
	}
	c[1] = 0;
	c[2] = b[1];
	for (int i = 3; i <= n; i++) {
		c[i] = 1ll * c[i - 1] + 1ll * (i - 1) * b[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] <= m) {
			ans = max(ans, i);
		}
	}
	while (c[ans] <= m) ans++;
	cout << ans;
	return 0;
}

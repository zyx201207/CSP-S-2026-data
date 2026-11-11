#include <bits/stdc++.h>

using namespace std;

int n, l, ans;
long long m, a[500010], s;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	
	for (int i = 1; i < n; i++) {
		s += (i - l) * (a[i] - a[i - 1]);
		while (s > m) {
			s -= a[i] - a[l];
			l += 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
}

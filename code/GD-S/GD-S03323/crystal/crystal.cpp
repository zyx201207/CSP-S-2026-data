#include <bits/stdc++.h>
using namespace std;

int n;
long long m, d, r, dans, ans, a[500005], da[500005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		d = m;
		r = i;
		for (long long i = 1; i <= n; i++)
			da[i] = a[i];
		while ((d >= 0) && (r < n)) {
			for (d; (d > 0) && (da[i] < i); d--)
				da[r]++;
			if (da[r] == i)
				dans++;
			r++;
		}
		ans = max(ans, dans);
	}
	cout << ans;
	return 0;
}

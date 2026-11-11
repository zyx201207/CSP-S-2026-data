#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 1;
ll n, m, a[N], d[N], cnt;
int l = 1, r = 1, ans;
bool f = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i ++) {
		d[i] = a[i] - a[i - 1];
		if (a[i] - a[i - 1] != a[i + 1] - a[i])
			f = 1;
	}
	if (! f) {
		if (m >= n * (n - 1) / 2 * (a[2] - a[1]))
			cout << n;
		else {
			for (int i = 1; i <= n; i ++)
				if (i * (i - 1) / 2 * (a[2] - a[1]) > m) {
					cout << i;
					return 0;
				}
			cout << n;
		}
		return 0;
	}
	cnt = 0;
	while (1) {
		while (r < n && cnt + d[r + 1] * (r - l + 1) <= m)
			cnt = (r - l + 1) * cnt + d[++ r];
		ans = max(ans, r - l + 1);
		if (r == n)
			break;
		while (l <= r && cnt + d[r + 1] * (r - l + 1) > m)
			cnt -= a[r] - a[l ++];
		if (l > r)
			break;
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/

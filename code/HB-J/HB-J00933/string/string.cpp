#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN], ans;
char c[MAXN];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	while (l <= r) {
		if (a[l] == a[r] && c[l] == c[r]) {
			l++;
			r--;
			continue;
		}
		if (c[l] != c[r]) {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				ans += a[r];
				r--;
			}
			else {
				a[r] -= a[l];
				ans += a[l];
				l++;
			}
		}
		else {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			}
			else {
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

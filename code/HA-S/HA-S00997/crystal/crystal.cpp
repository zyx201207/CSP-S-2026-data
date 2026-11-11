#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[500005], b[500005], l, r, ans, t, tp;
bool B = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; ++i) {
		b[i] = b[i - 1] + a[i];
	}
	if ((((a[1] + a[n]) * n) >> 1) == b[n]) {
		B = 1;
	}
	for (int j = 1; j <= n; ++j) {
		ll l = 1, r = j, i = 0;
		while (l < r) {
			i = (l + r) >> 1;
			if ((b[j] - b[i - 1]) >= (j - i + 1) * a[j] - m) {
				r = i;
			} else {
				l = i + 1;
			}
		}
		ll tl = j - i + 1;
//		cout << tl << " ";
		ans = max(tl, ans);
	}
	if (B) {
		--ans;
	}
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200005], cnt, ans;
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1, j = n; i < j; i++, j--) {
		cnt = a[i] - a[j];
		if (!cnt) {
			if (c[i] == c[j]) {
				continue;
			} else {
				ans += a[i];
				continue;
			}
		} else if (cnt > 0) {
			if (c[i] != c[j]) {
				ans += a[j];
			}
			while (cnt && i < j) {
				ll d;
				if (cnt < 0) {
					cnt += a[++i];
					d = a[i];
				}
				else if (cnt > 0) {
					cnt -= a[--j];
					d = a[j];
				}
				if (c[i] != c[j]) {
					if (cnt < 0) {
						ans += -cnt;
						i++;
					} else if (cnt > 0) {
						ans += a[i] - cnt;
						j--;
					} else {
						ans += d;
					}
				} else {
					if (cnt < 0) {
						i++;
					} else if (cnt > 0) {
						j--;
					}
				}
			}
			if (i >= j) break;
		} else {
			if (c[i] != c[j]) {
				ans += a[i];
			}
			while (cnt && i < j) {
				ll d;
				if (cnt < 0) {
					cnt += a[++i];
					d = a[i];
				}
				else if (cnt > 0) {
					cnt -= a[--j];
					d = a[j];
				}
				if (c[i] != c[j]) {
					if (cnt < 0) {
						ans += -cnt;
						i++;
					} else if (cnt > 0) {
						ans += a[i] - cnt;
						j--;
					} else {
						ans += d;
					}
				} else {
					if (cnt < 0) {
						i++;
					} else if (cnt > 0) {
						j--;
					}
				}
			}
			if (i >= j) break;
		}
	}
	cout << ans;
	return 0;
}

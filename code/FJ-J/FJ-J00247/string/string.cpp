#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int a[N];
ll sum[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n <= 2000) {
		string s = "";
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> c[i];
			for (int j = 1; j <= a[i]; ++j) {
				s = s + c[i];
			}
		}
		int mid = s.size() / 2;
		int ans = 0;
		for (int i = 0; i < mid; ++i) {
			if (s[i] != s[s.size() - i - 1]) ++ans;
		}
		cout << ans << '\n';
	} else if (n <= 200000) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> c[i];
			sum[i] = sum[i - 1] + a[i];
		}
		ll ans = 0, mid = sum[n] / 2;
		int r = n;
		for (int i = 1; i <= n; ++i) {
			if (sum[i] > mid) break;
			if (c[i] != c[r]) {
				if (a[i] > a[r]) {
					while (a[i] > a[r]) {
						ans += a[r];
						r--;
						a[i] -= a[r];
					}
					ans += a[i];
				} else {
					ans += a[i];
					a[r] -= a[i];
					if (r == 0) --r;
				}
			} else {
				if (a[i] > a[r]) {
					while (a[i] > a[r] && c[i] == c[r]) {
						a[i] -= a[r];
						r--;
					}
					if (c[i] == c[r]) {
						a[r] -= a[i];
					} else {
						ans += a[i];
						a[r] -= a[i];
					}
				}
				if (r <= 0) --r;
			}
		}
		cout << ans + a[n / 2] << '\n';
	}
	return 0;
}

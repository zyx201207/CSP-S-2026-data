#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
int a[N];
ll sum[N];
char c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum[i] = sum[i - 1] + a[i];
	}
	ll len = sum[n], midlen = len / 2, midpos = -1;
	for (int i = 1; i <= n; i++) {
		if (sum[i] >= midlen) {
			midpos = i;
			break;
		}
	}
	ll ans = 0;
	for (int l = 1, r = n; l <= midpos; l++) {
		ll l1 = sum[l - 1] + 1, r1 = sum[l];
		ll hl = len - r1 + 1, hr = len - l1 + 1;
		for (; r >= midpos; r--) {
			ll l2 = sum[r - 1] + 1, r2 = min(sum[r], hr);
			if (hl < l2) {
				if (c[l] != c[r]) ans += r2 - l2 + 1;
			} else {
				if (c[l] != c[r]) ans += r2 - hl + 1;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

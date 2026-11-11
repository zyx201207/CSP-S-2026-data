#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, a[N], l, r, cnt;
char c[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	while (l < r) {
		if (a[l] == a[r]) {
			if (c[l] != c[r]) cnt += a[l];
			l++, r--;
		}
		else if (a[l] < a[r]) {
			a[r] -= a[l];
			if (c[l] != c[r]) cnt += a[l];
			l++;
		}
		else {
			a[l] -= a[r];
			if (c[l] != c[r]) cnt += a[r];
			r--;
		}
	}
	cout << cnt;
	return 0;
}


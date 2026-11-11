#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;

int a[N];

char c[N];

int ans;

signed main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
//	ios :: sync_with_stdio (0), cin.tie (0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	while (l < r) {
		if (c[l] == c[r]) {
			int similarity = min (a[l], a[r]);
			a[l] -= similarity;
			a[r] -= similarity;
		}
		else {
			int difference = min (a[l], a[r]);
			a[l] -= difference;
			a[r] -= difference;
			ans += difference;
		}
		if (a[l] == 0) {
			l++;
		}
		if (a[r] == 0) {
			r--;
		}
	}
	cout << ans;
	return 0;
}

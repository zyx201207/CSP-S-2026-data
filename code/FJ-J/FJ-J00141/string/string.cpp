#include <bits/stdc++.h>
using namespace std;

long long L, n, t[200005], a[200005], l, r, pre[200005], ans;
char tc[200005], b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> tc[i];
		l += t[i];
		pre[i] = pre[i - 1] + t[i];
	}
	
	if (l & 1) {
		int f = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (pre[i - 1] < l / 2 + 1 && l / 2 + 1 < pre[i]) {
				f = 1;
				a[i] = l / 2 - pre[i - 1];
				b[i] = b[i + 1] = tc[i];
				a[++i] = pre[i] - l / 2 - 1;
			} else a[i] = t[i - f], b[i] = tc[i - f];
		}
	} else {
		int f = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (pre[i - 1] < l / 2 && l / 2 < pre[i]) {
				f = 1;
				a[i] = l / 2 - pre[i - 1];
				b[i] = b[i + 1] = tc[i];
				a[++i] = pre[i] - l / 2;
			} else a[i] = t[i - f], b[i] = tc[i - f];
		}
	}
	
	l = 1, r = n + 1;
	while (l < r) {
		if (b[l] != b[r]) {
			if (a[l] > a[r]) a[l] -= a[r], ans += a[r], a[r] = 0;;
			if (a[l] == a[r]) ans += a[l], a[l] = a[r] = 0;
			if (a[l] < a[r]) a[r] -= a[l], ans += a[l], a[l] = 0;
		} else {
			if (a[l] > a[r]) a[l] -= a[r], a[r] = 0;
			if (a[l] == a[r]) a[l] = a[r] = 0;
			if (a[l] < a[r]) a[r] -= a[l], a[l] = 0;
		}
		if (!a[l]) l++;
		if (!a[r]) r--;
	}
	cout << ans;
	
	return 0;
} 

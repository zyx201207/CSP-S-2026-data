#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	ll cnt = 0;
	ll a[n];
	char c[n];
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	if (1) {
		ll m = sum / 2;
		int l = 0, r = n - 1;
		while (l < r) {
			ll subs;
			if (a[l] < a[r]) {
				subs = a[l];
				if (c[l] != c[r]) cnt += subs;
				l++;
				a[r] -= subs;
			} else {
				subs = a[r];
				if (c[l] != c[r]) cnt += subs;
				r--;
				a[l] -= subs;
			}
		}
	}
	cout << cnt;
	return 0;
}

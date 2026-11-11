#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using plc = pair<ll, char>;

const int N = 2e5 + 5;
plc a[N];

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ll n;
	cin >> n;

	ll len = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
		len += a[i].first;
	}

	ll hl = len / 2;
	ll l_len = 0;
	ll min_c = 0;
	ll l = 1, r = n;
	while (l <= r) {
		ll l_l = min(a[l].first, hl - l_len);
		a[l].first -= l_l;
		l_len += l_l;
		char l_c = a[l].second;

		ll r_len = 0;
		while (r >= l) {
			ll r_l = min(a[r].first, l_l - r_len);
			a[r].first -= r_l;
			r_len += r_l;
			char r_c = a[r].second;
			if (l_c != r_c) min_c += r_l;
			if (r_len == l_l) break;
			r--;
		}
		if (l_len == hl) break;
		l++;
	}

	cout << min_c << "\n";
	return 0;
}


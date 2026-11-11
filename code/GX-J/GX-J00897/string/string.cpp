#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x;
}
ll n, sum, res;
vector<pair<ll, ll> > v[26];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) {
		ll x;
		char c;
		x = read();
		c = getchar();
		while (c < 'a' || c > 'z') {
			c = getchar();
		}
		int y = c - 'a';
		v[y].push_back({sum + 1, x});
		sum += x;
	}
	ll k = sum >> 1;
	for (int i = 0; i < 26; i++) {
		for (pair<ll, ll> j : v[i]) {
			if (j.first > k) {
				break;
			}
			pair<ll, ll> t;
			ll len = j.second;
			ll ans = len;
			t.first = sum - (j.first + len - 1) + 1;
			t.second = 0;
			int idx = lower_bound(v[i].begin(), v[i].end(), t) - v[i].begin();
			pair<ll, ll> l, r;
			if (idx != (int)(v[i].size())) {
				r = v[i][idx];
			} else {
				r = {sum + 1, 0};
			}
			if (idx) {
				l = v[i][idx - 1];

			} else {
				l = {0, 0};
			}
			if (l.first + l.second - 1 >= t.first) {
				ll d = min(l.first + l.second - 1, t.first + len - 1) - t.first + 1;
				ans -= d;
			}
			if (r.first <= t.first + len - 1) {
				ll dd = min(r.first + r.second - 1, t.first + len - 1) - r.first + 1;
				ans -= dd;
			}
			res += ans;
		}
	}
	cout << res;
	return 0;
}

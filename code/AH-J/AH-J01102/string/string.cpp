#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s = "";
	ll ans = 0;
	ll n, a;
	char c;
	cin >> n;
	for (ll i = 0; i < n; i ++) {
		cin >> a >> c;
		for (ll j = 0; j < a; j ++) {
			s += c;
		}
	}
	if (s.size() % 2 != 0) {
		for (ll i = 0; i < ((s.size() + 1) / 2); i ++) {
			if (s[i] != s[s.size() - 1 - i]) {
				ans ++;
			}
		}
	} else {
		for (ll i = 0; i < s.size() / 2; i ++) {
			if (s[i] != s[s.size() - 1 - i]) {
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}

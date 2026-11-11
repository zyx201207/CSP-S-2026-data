#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 10;

ll n, a[N], sum;
string s, t;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		char q; cin >> q;
		
		for (int j = 1; j <= x; j++) s += q, sum++;
	}
	ll f = 0;
	for (int i = 1; i < s.size(); i++) if (s[i] != s[i - 1]) f = 1;
	if (f == 0) {
		cout << 0;
		return 0;
	}
	
	ll l = 0, r = sum, ok = 0, ans = 0;
	for (int i = 1; i <= sum / 2 + 1; i++) {
		if (s[l] != s[r]) ok = 1;
		if (s[l] == s[r]) ans = max(ans, r - l + 1);
	}
	if (ok) cout << (sum - ans) / 2;
	else cout << 0;
	return 0;
} 

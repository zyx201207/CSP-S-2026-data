#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

ifstream fin("and.in");
ofstream fout("and.out");

#define cin fin
#define cout fout

bool (ll a) {
	while (a != 1) {
		if (a % 2 != 0) return false;
		a /= 2;
	}
}
int main() {
	ll n,m;
	cin >> n >> m;
	
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(),a.end(),greater<ll>());
	if (m == 1 && n >= 2) {
		cout << a[0];
		return 0;
	}
	if (m == n) {
		ll ans = a[0];
		for (ll i = 0; i < n; i++) ans = ans & a[i];
		cout << ans;
		return 0;
	}
	if (do(n)) {
		cout << 0;
		return 0;
	}  
	ll ans = a[0];
	ll pos = 0;
	while (m--) ans = (ans & a[pos++]);
	cout << ans;
	return 0;
}

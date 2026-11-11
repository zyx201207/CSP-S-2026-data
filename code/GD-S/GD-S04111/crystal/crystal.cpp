#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, m;
vector<ll> a;

bool check(ll x) {
	if (x == 0) return true;
	for (int i = 1; i + x - 1 <= n; ++i) {
		ll mx = a[i + x - 1];
		ll cnt = 0;
		bool flg = true;
		for (int j = i; j < i + x - 1; ++j) {
			cnt += mx - a[j];
			if (cnt > m) {
				flg = false;
				break;
			}
		}
		if (flg) return true;
	}
	return false;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	sort(a.begin(), a.end());
	
	ll l = 0, r = n;
	while(l < r) {
		ll mid = l + (r - l) / 2;
		bool flg = check(mid);
		if (flg) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	
	cout << l - 1 << '\n';
	
	return 0;
} 

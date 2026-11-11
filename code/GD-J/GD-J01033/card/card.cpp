#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 5e5 + 10, M = 3e5 + 10;
ll n, m;
ll a[N];
map<ll, ll> cnt;

void solve() {
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<ll> vt;
	for(ll i = 1; i <= n; i ++) {
		map<ll, bool> vis;
		for(ll j = i; j <= n; j ++) {
			if(vis.count(a[i]) == 0) {
				vt.push_back(a[i]);
				vis[a[i]] = 1;
			}
			else {
				while(vt.size() && vt.back() != a[i]) vt.pop_back();
			}
		}
		while(vt.size()) {
			cnt[vt.back()] ++;
			vt.pop_back();
		}
	}
	for(ll i = 1; i <= m; i ++) {
		cout << cnt[i] << ' ';
	}
	return;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	solve();
	
	return 0;
}

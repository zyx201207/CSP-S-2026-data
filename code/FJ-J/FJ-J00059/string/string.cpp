#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n = 0;
ll _tot = 0, ans = 0;
vector<pair<char, ll> > v, rev;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		ll a;
		char c;
		cin >> a >> c;
		v.push_back({c, a});
		rev.push_back({c, a});
	}
	reverse(rev.begin(), rev.end());
	for(int i = 0; i < n; i++) {
		_tot += rev[i].second;
		rev[i].second = _tot;
	}
	if(_tot <= 1e8) {
		int _now = 1;
		char cc[(int)_tot + 1];
		for(auto it : v) {
			for(int i = _now; i <= _now + it.second; i++) 
				cc[i] = it.first;
			_now += it.second;
		}
		int i = 1, j = _tot;
		while(i < j) {
			if(cc[i] != cc[j]) 
				ans++;
		}
		cout << ans;
		return 0;
	}
	_tot = 0;
	for(int i = 0; i < n; i++) {
		_tot += v[i].second;
		v[i].second = _tot;
	}
	int i = 0, j = 0;
	while(i < n && j < n && (v[i].second <= _tot / 2 || rev[i].second <= _tot / 2)) {
		if(v[i].second > rev[j].second) {
			if(v[i].first != rev[j].first) {
				if(i == 0 && j == 0)
					ans += rev[j].second;
				else if(i == 0) 
					ans += rev[j].second - rev[j - 1].second;
				else ans += rev[j].second - v[i - 1].second;
			}
			j++;
		} else if(v[i].second < rev[j].second) {
			if(v[i].first != rev[j].first) {
				if(j == 0 && i == 0)
					ans += v[i].second;
				else if(j == 0) 
					ans += v[i].second - v[i - 1].second;
				else ans += v[i].second - rev[j - 1].second;
			}
			i++;
		} else {
			if(v[i].first != rev[j].first) {
				ll s = LLONG_MAX, ss = LLONG_MAX;
				if(i > 0)
					s = v[i].second - v[i - 1].second;
				else s = v[i].second;
				if(j > 0)
					ss = rev[j].second - rev[j - 1].second;
				else ss = rev[j].second;
				ans += min(s, ss);
			}
			i++, j++;
		}
	}
	cout << ans;
	return 0;
}
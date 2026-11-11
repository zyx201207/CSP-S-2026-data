#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5 + 10;
ll n;
vector<pair<ll, char>> vt; 
ll sz = 0;
bool f = 0;
ll ans = 0;

void solve() {
	cin >> n;
	for(ll i = 1; i <= n; i ++) {
		ll a; char c;
		cin >> a >> c;
		if(vt.size() && vt.back().second == c) vt.back().first += a;
		else if(vt.size()) vt.push_back({vt.back().first + a, c});
		else vt.push_back({a, c});
		sz += a;
	}
//	for(ll i = 0; i < vt.size(); i ++) cout << vt[i].first << ' ' << vt[i].second << '\n';
	ll mid = sz / 2 + (sz & 1);
	ll L = 0, R = 0;
	char c;
	for(ll i = 0; i < vt.size(); i ++) {
		L = R + 1;
		R = vt[i].first;
		c = vt[i].second;
		if(!f) {
			if(R >= mid) {
				f = 1;
				ll d1 = abs(R - mid);
				ll d2 = abs(L - mid);
				if(d1 != d2) {
					if(d1 > d2) {
						ans += d1 - d2;
					}
				}
//				ans += max(d1, d2) - min(d1, d2);
//				printf("ans = %lld\n", ans);
			}
		}
		else {
			ll R_ = mid - abs(L - mid) + !(sz & 1);
			ll L_ = mid - abs(R - mid) + !(sz & 1); // r_ < l_ < mid < l < r
			ll L_idx = upper_bound(vt.begin(), vt.end(), pair<ll, char>{L_, 0}) - vt.begin();
			ll R_idx = lower_bound(vt.begin(), vt.end(), pair<ll, char>{R_, 0}) - vt.begin();
//			printf("[%lld, %lld] -> [%lld, %lld] -> %lld %lld\n", L, R, L_, R_, L_idx, R_idx);
			for(ll j = L_idx; j <= R_idx; j ++) {
				ll jL, jR = vt[j].first;
				if(j == 0) jL = 1;
				else jL = vt[j - 1].first + 1;
//				printf("  fc[%lld, %lld]: ", jL, jR);
				if(vt[j].second != c) {
					if(jL <= L_ && jR >= L_ && jR < R_) {
//						cout << "c1\n";
//						printf("  %lld", ans);
						ans += jR - L_ + 1;
//						printf(" -> %lld\n", ans);
					}
					else if(jL > L_ && jL <= R_ && jR >= R_) {
						ans += R_ - jL + 1;
//						cout << "c2\n";
					}
					else if(jL <= L_ && jR >= R_) {
						ans += R_ - L_ + 1;
//						cout << "c4\n";
					}
					else {
						ans += jR - jL + 1;
//						cout << "c3\n";
					}
				}
			}
		}
	}
	cout << ans;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	solve();
	
	return 0;
}

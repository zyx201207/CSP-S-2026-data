#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	ll x;
	char c;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;

	cin >> n;
	
	vector<Node> vec;
	
	ll num = 0;
	for (ll i = 1;i <= n;i ++) {
		ll x;
		char c;  // º¬Òå: x¸ö×ÖÄ¸c
		cin >> x >> c;
		
		num += x;
		vec.push_back({x, c}); 
	}
	
	ll l = 0, r = n - 1, ans = 0;
	while (l < r) {
		if (vec[l].x == vec[r].x) {
			if (vec[l].c != vec[r].c) {
				ans += vec[l].x;
			}
			l ++;
			r --;
			continue;
		}
		
		if (vec[l].x > vec[r].x) {
			if (vec[l].c != vec[r].c) {
				ans += vec[r].x;
			}
			
			ll cnt = vec[r].x;
			while (r > l && cnt < vec[l].x) {
				ll can = min(vec[r - 1].x, vec[l].x - cnt);
				
				if (vec[r - 1].c != vec[l].c) {
					ans += can;
				}
				vec[r - 1].x -= can;
				r --;
				cnt += can;
			}
			l ++;
			continue;
		}
		
		if (vec[r].x > vec[l].x) {
			if (vec[l].c != vec[r].c) {
				ans += vec[l].x;
			}
			
			ll cnt = vec[l].x;
			while (l < r && cnt < vec[r].x) {
				ll can = min(vec[l + 1].x, vec[r].x - cnt);
				
				if (vec[l + 1].c != vec[r].c) {
					ans += can;
				}
				vec[l + 1].x -= can;
				cnt += can; 
				l ++;
			}
			r --;
			continue;
			
		}
	} 
	
	cout << ans; 
	return 0;
}
/*
100
*/

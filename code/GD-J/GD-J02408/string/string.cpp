#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;

//#define LOCAL

namespace my {
	// Globals
	
	typedef long long ll;

	constexpr int N = 2e6 + 10;
	
	ll a[N]; char c[N];
	ll pre[N], bl[N], br[N]; 

	int main() {
		#ifndef LOCAL
			freopen("string.in", "r", stdin);
			freopen("string.out", "w", stdout);
			
			ios::sync_with_stdio(false);
			cin.tie(nullptr);
		#endif

		int n; cin >> n;
		
//		cerr << "Test# 1\n";
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt++; cin >> a[cnt] >> c[cnt];
			
			if (cnt > 1 && c[cnt] == c[cnt - 1]) {
				a[cnt - 1] += a[cnt]; cnt--;
			}
		}
		
		n = cnt;
		
		if (n == 1) {
			cout << "0\n"; return 0;
		}
			
		pre[0] = 0;
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + a[i];
			
		for (int i = 1; i <= n; i++) {
			bl[i] = pre[i - 1] + 1; 
			br[i] = pre[i];
		}
			
		ll hlf = pre[n] >> 1, L = pre[n];
		int spl = 0;
		for (int i = 1; i <= n; i++)
			if (pre[i - 1] + 1 <= hlf && pre[i] > hlf) {
				spl = i; break;
			}
			
		if (spl && br[spl] > hlf) {
			ll newl = hlf + 1, newr = br[spl];
			
			for (int i = spl + 1; i <= n; i++) {
				bl[i + 1] = bl[i];
				br[i + 1] = br[i];
			}
			
			br[spl] = hlf;
			bl[spl + 1] = newl; br[spl + 1] = newr;
			c[spl + 1] = c[spl];
			n++;
		}
		
//		for (int i = 1; i <= n; i++)
//			printf("l = %lld, r = %lld, c = %c\n", bl[i], br[i], c[i]);
		
		map <ll, ll> st[26];
		
		ll ans = 0;
		for (int i = n; i >= 1; i--) {
			ll l = bl[i], r = br[i];
			int nc = c[i] - 'a';
			
//			printf("For chunk: %lld %lld\n", l, r);
			
			if (l > hlf) st[nc][l] = r;
			else {
				ll mod_r = L + 1 - l;
				ll mod_l = L + 1 - r;
				
//				printf("  - Modify %lld %lld\n", mod_l, mod_r);
				
				ll cost = r - l + 1;
				
				for (auto it = st[nc].cbegin(); it != st[nc].cend(); ++it) {
					ll pl = it->first, pr = it->second;
					
//					printf("  - Use chunk %lld %lld\n", pl, pr);
					
//					if (pl > mod_r) break;
					
					pl = max(pl, mod_l);
					pr = min(pr, mod_r);
					
					cost -= min(cost, pr - pl + 1);
					if (!cost) break;
				}
				
//				printf("  - cost = %lld\n", cost);
				
				ans += cost;
			}
		}
		
		cout << ans << endl;

		return 0;
	}
}

int main() {
	my::main();

	return 0;
}

/*
3
2 a
2 b
6 a
*/

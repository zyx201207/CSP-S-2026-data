#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

namespace my {
	constexpr int N = 5e5 + 5;
	constexpr int MOD = 998244353;
	
	typedef long long ll;
	typedef unsigned long long ull;
	
	ll a[N];
	ll f[N]; // 将前面 i 个水晶的能量值增加到 a[i] 的操作次数 
	ll f2[N];
	int main() {
		#ifndef LOCAL
			freopen("crystal.in", "r", stdin);
			freopen("crystal.out", "w", stdout);
		#endif

		int n; ull m; scanf("%d%llu", &n, &m);
		
		bool flagA = true, flagB = true;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			
			flagA &= a[i] == i;
			if (i > 2) flagB = a[i] - a[i - 1] == a[i - 1] - a[i - 2]; 
		}
			
		sort(a + 1, a + 1 + n);
		
//		puts("Sorted: ");
//		for (int i = 1; i <= n; i++)
//			printf("%lld ", a[i]);
//		putchar('\n');

////      f 这样算： 
//		for (int i = 1; i <= n; i++) {
//			f[i] = f[i - 1];
//			f[i] += (a[i] - a[i - 1]) * (i - 1);
//		}
		
		auto cal_f = [&] (int l, int r) -> ll {
			f2[l] = 0;
			for (int i = l + 1; i <= r; i++)
				f2[i] = f2[i - 1] + (a[i] - a[i - 1]) * (i - l);
				
			return f2[r]; 
		};
		
		
		if (false) {
			int ans = 1, pt = 0;
			ll cost = 0;
			for (int i = 1; i <= n; i++) {
	//			while (pt < n && cost + (ll)(a[pt + 1] - a[pt]) * pt <= m) {
	////				puts("Advance!");
	//				cost += (ll)(a[pt + 1] - a[pt]) * pt;
	//				pt++;
	//			}
	
				while (pt < n && cal_f(i, pt + 1) <= m) {
	//				puts("Advance!");
	//				cost += (ll)(a[pt + 1] - a[pt]) * pt;
					pt++;
				}
				
//				printf("For i = %d: pt = %d, cost = %lld, f = %lld\n", i, pt, cost, cal_f(i, pt));
				
				ans = max(ans, pt - i + 1);
				cost -= (ll)(a[i + 1] - a[i]) * i;
			}
			
			printf("%d\n", ans);
			
			return 0;
		}
		else {
			if (false) {
				int ans = 1;
				while (ans <= n && (ll)ans * (ans + 1) >> 1 <= m) ans++;
				printf("%d\n", max(1, ans - 1));
			}
			else {
				cal_f(1, n);
				
				for (int i = 1; i <= n; i++)
					f[i] = f2[i];
				
				auto cal = [&] (int l, int r) -> ll {
					ll t = f[r] - f[l - 1];
					t -= (a[r] - a[l - 1]) * (l - 1);
					
					return t;
				};
				
				int ans = 1, pt = 0;
				for (int i = 1; i <= n; i++) {
					while (pt < n && cal(i, pt + 1) <= m) {
						pt++;
					}
					
					ans = max(ans, pt - i + 1);
//					printf("For i = %d, pt = %d, cal = %lld, cal_f = %lld\n", i, pt, cal(i, pt), cal_f(i, pt));
				}
				
				printf("%d\n", ans);
				
				return 0;
			}
		}
		

		#ifndef LOCAL
			fclose(stdin);
			fclose(stdout);
		#endif

		return 0;
	}
}

int main() {
	my::main();

	return 0;
}


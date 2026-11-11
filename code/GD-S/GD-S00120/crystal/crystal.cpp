#include <bits/stdc++.h>
#include <assert.h>
namespace cjdst{
	typedef long long ll;
	typedef unsigned long long ull;
	typedef std::pair <int, int> pii;
	typedef std::pair <ll, ll> pll;
	
	void init(){
		std::ios::sync_with_stdio(0);
		std::cin.tie(0), std::cout.tie(0);
	}
	
	/*
	考虑枚举 [l, r]，把 A_l,..., 一直弄到 A_r，这样是 O(n^2) 的 
	然后考虑双指针，就能 O(n) 了 
	2e18，不会炸吧？ 
	*/
	
	const int N = 500000;
	ll a[N + 5];
	ll n, m;
	
	void solve(){
		std::cin >> n >> m;
		for(int i = 1; i <= n; i++) std::cin >> a[i];
		std::sort(a + 1, a + n + 1);
		ll r = 1, cur = 0, ans = 1;
		for(int i = 1; i <= n; i++){
			if(i > 1){
				cur -= (a[r] - a[i - 1]);
			}
			while(r < n && cur + (a[r + 1] - a[r]) * (r - i + 1) <= m){
				cur += (a[r + 1] - a[r]) * (r - i + 1);
				r++;
			}
			ans = std::max(ans, r - i + 1);
			// std::cout << r << ' ';
		}
		std::cout << ans << '\n';
	}
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cjdst::init();
	int T = 1;
	// std::cin >> T;
	for(int _ = 1; _ <= T; _++){
		cjdst::solve();
	} 
}


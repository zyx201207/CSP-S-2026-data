#include<bits/stdc++.h>
#define i32 int
#define i64 long long
#define u32 unsigned
#define u64 unsigned long long
#define pb push_back
#define mp std::make_pair
#define all(arr) arr.begin(), arr.end()
#define CNOI CSPJS_NOIP_GDOI_NOI_CTS
#define CFR Div4_Div3_Div2_Div1
#define ATC ABC_ARC_AGC_AHC
#define RPPP RP_PLUS_PLUS
namespace I_AK_CNOI_CFR_ATC_RPPP {
	void solve() {
		// 应该是从后往前，每次加一个，如果有的那就把中间全部清零
		i64 n, m; std::cin >> n >> m;
		std::vector<i64> cnt(m, 0), arr, a(n);
		for(i64 i = 0;i < n;i ++) std::cin >> a[i];
		// 但是会有还原
		// 先来把A给打了
		bool chk_A = true;
		for(i64 i = 1;i < n;i ++)
			if(a[i - 1] > a[i]) {
				chk_A = false;
				break;
			}
		if(chk_A) {
			for(i64 i = 1;i <= m;i ++) {
				std::cout << std::upper_bound(all(a), i) - a.begin() << " ";
			}
			std::cout << std::endl;
			return;
		}
		for(i64 i = 0;i < n;i ++) {
			for(i64 j = i;j < n;j ++) {
				if(!std::count(all(arr), a[j] - 1)) arr.pb(a[j] - 1);
				else while(arr.back() != a[j] - 1) arr.pop_back();
			}
			for(const auto &x : arr) cnt[x] ++; arr.clear();
		}
		for(i64 i = 0;i < m;i ++) std::cout << cnt[i] << " ";
		std::cout << std::endl;
		return;
	}
};
i32 main() {
	std::freopen("card.in", "r", stdin);
	std::freopen("card.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; // std::cin >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

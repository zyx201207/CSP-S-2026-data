#include<bits/stdc++.h>
#define i32 int
#define i64 long long
#define u32 unsigned
#define u64 unsigned long long
#define pb push_back
#define mp std::make_pair
#define all(Arr) Arr.begin(), Arr.end()
#define CNOI CSP_J_S_NOIP_GDOI_NOI_CTS
#define CFR CFDiv1_CFDiv2_CFDiv3_CFDiv4
#define ATC ABC_ARC_AGC_AHC
#define RPPP RP_Plus_Plus
namespace I_AK_CNOI_CFR_ATC_RPPP {
	void solve() {
		i64 n, d; std::cin >> n >> d;
		std::vector<i64> x(n);
		for(i64 i = 0;i < n;i ++) {
			std::cin >> x[i];
		}
		i64 ans = 0;
		for(i64 i = 1;i < n;i ++) {
			if(x[i] - x[i - 1] == 3) {
				ans ++;
			}
		}
		std::cout << ans << "\n";
		return;
	}
};
i32 main() {
	// std::freopen("migrate.in", "r", stdin);
	// std::freopen("migrate.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; std::cin >> tt >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

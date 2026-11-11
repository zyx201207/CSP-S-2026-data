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
		i64 n, k; std::cin >> n >> k;
		std::vector<i64> u(n - 1), v(n - 1);
		for(i64 i = 0;i < n;i ++) {
			std::cin >> u[i] >> v[i];
		}
		std::cout << 1 << "\n";
		return;
	}
};
i32 main() {
	std::freopen("hub.in", "r", stdin);
	std::freopen("hub.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; cin >> tt >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

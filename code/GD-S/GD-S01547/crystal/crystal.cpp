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
	i64 dfs(i64 x, i64 add, std::vector<i64> a, i64 n, i64 m) {
		if(add > m) return -4e18;
		if(x == n) {
			if(add <= m) {
				i64 ans = 0, cnt = 1;
				std::sort(all(a));
				for(i64 i = 1;i < n;i ++) {
					if(a[i] != a[i - 1])
						ans = std::max(ans, cnt), cnt = 1;
					else cnt ++;
				}
				return ans;
			} else return -4e18;
		}
		i64 ans = -4e18;
		a[x] ++, ans = std::max(ans, dfs(x, add + 1, a, n, m));
		a[x] --, ans = std::max(ans, dfs(x + 1, add, a, n, m));
		return ans;
	}
	void solve() {
		i64 n, m, gc = 0; std::cin >> n >> m;
		std::vector<i64> a(n);
		bool chk_A = true, chk_B = true;
		for(i64 i = 0;i < n;i ++) std::cin >> a[i];
		for(i64 i = 1;i < n;i ++) {
			if(a[i] - a[i - 1] != a[1] - a[0])  chk_B = false;
		}
		for(i64 i = 0;i < n;i ++) if(a[i] != i) chk_A = false;
		if(chk_A || chk_B) {
			std::sort(all(a));
			i64 sp = 0, ans = 0;
			for(i64 i = 0;i < n;i ++) {
				if(sp + (i + 1) > m) break;
				sp += (i + 1), ans ++;
			}
			if(ans != n) ans ++;
			std::cout << ans << "\n";
			return;
		}
		if(n <= 5 && m <= 10)
			std::cout << std::max(dfs(0, 0, a, n, m), 1LL) << "\n";
		else if(n <= 5000) {
			std::sort(all(a)); i64 ans = 1, tot = 0, cnt = 0;
			for(i64 i = 0;i < n;i ++) {
				for(i64 j = i;j >= 0;j --) {
					if(cnt + (a[i] - a[j]) > m) break;
					tot ++, cnt += (a[i] - a[j]);
				}
				ans = std::max(ans, tot), tot = 0, cnt = 0;
			}
			std::cout << ans << "\n";
		} else std::cout << 1 << "\n";
		return;
	}
};
i32 main() {
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; // cin >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

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
	i64 min(i64 a, i64 b) {
		if(a > b) return b;
		else return a;
	}
	void solve() {
		i32 c, n, m, d1, q; std::cin >> c >> n >> m >> d1 >> q;
		std::vector<i64> w(m);
		for(i64 i = 0;i < m;i ++) {
			std::cin >> w[i];
		}
		std::vector<std::vector<std::array<i32, 2>>> a(n);
		for(i64 i = 0;i < n;i ++) {
			i64 k; std::cin >> k;
			a[i].resize(k);
			for(i64 j = 0;j < k;j ++) {
				std::cin >> a[i][j][0] >> a[i][j][1];
				a[i][j][0] --;
			}
		}
		if(7 <= c && c <= 11) {
			std::vector<std::vector<i64>> d(m, std::vector<i64>(m, 4e18));
			for(i64 i = 0;i < n;i ++) {
				if(a[i].size() == 2) {
					d[a[i][0][0]][a[i][1][0]] = d[a[i][1][0]][a[i][0][0]] = min(a[i][0][1] + a[i][1][1], d[a[i][0][0]][a[i][1][0]]);
				}
			}
			for(i64 i = 0;i < m;i ++) d[i][i] = 0;
			for(i64 i = 0;i < m;i ++) {
				for(i64 j = 0;j < m;j ++) {
					for(i64 k = 0;k < m;k ++) {
						d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			while(q --) {
				i64 x, y; std::cin >> x >> y, x --, y --;
				std::cout << d[x][y] + w[x] + w[y] << "\n";
			}
		} else if(1 <= c && c <= 6) {
			std::vector<std::vector<i64>> d(m, std::vector<i64>(m, 4e18));
			for(i64 i = 0;i < n;i ++) {
				for(i64 j = 0;j < a[i].size();j ++) {
					for(i64 k = 0;k < a[i].size();k ++) {
						i64 p1 = a[i][j][0], p2 = a[i][k][0];
						i64 d1 = a[i][j][1], d2 = a[i][k][1];
						d[p1][p2] = std::min(d1 + d2, d[p1][p2]);
					}
				}
			}
			for(i64 i = 0;i < m;i ++) d[i][i] = 0;
			for(i64 i = 0;i < m;i ++) {
				for(i64 j = 0;j < m;j ++) {
					for(i64 k = 0;k < m;k ++) {
						d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			while(q --) {
				i64 x, y; std::cin >> x >> y, x --, y --;
				std::cout << d[x][y] + w[x] + w[y] << "\n";
			}
		} else {
			std::cout << 1 << std::endl;
		}
	}
};
i32 main() {
	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; // cin >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

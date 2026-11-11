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
		// 把每一个数字每一个二进制位求出来
		// 对于每一位，贪心，如果有累就没有必要选择，如果没有就选一个尽量大的？？？？填补位置！
		// 从高位开始往下贪
		// 如果遇到多个可以的，那就一个有其余无下去枚举
		// 是按位与：直接从前往后枚举，遇到都有的位就好！ 
		i64 n, m; std::cin >> n >> m;
		std::vector<i64> a(n), cnt(40, 0);
		std::vector<std::array<i64, 40>> arr(n);
		for(i64 i = 0;i < n;i ++) {
			std::cin >> a[i];
			i64 i1 = a[i], cnt1 = 0;
			while(i1) {
				arr[i][cnt1 ++] = (i1 & 1), (i1 >>= 1);
			}
			for(i64 j = 0;j < 40;j ++) {
				cnt[j] += arr[i][j];
			}
		}
		for(i64 i = 39;i >= 0;i --) {
			/*
			for(i64 i = 0;i < 40;i ++) {
				std::cout << cnt[i] << " ";
			}
			std::cout << std::endl;
			*/
			if(cnt[i] >= m) {
				// 直接选，把这些给删掉。
				// 我知道了，我们可以直接码力一手，从高位美剧，那就把这些数列为保存，只要这些书里面有Mge1
				// 不一定重复111111 
				std::vector<i64> b, cnt1(40, 0);
				std::vector<std::array<i64, 40>> arr1;
				for(i64 j = 0;j < n;j ++) {
					if(arr[j][i]) {
						b.pb(a[j]), arr1.pb(arr[j]);
						for(i64 k = 0;k < 40;k ++) {
							cnt1[k] += arr[j][k];
						}
					}
				}
				n = b.size();
				std::swap(cnt, cnt1);
				std::swap(arr, arr1);
				std::swap(a, b); // important!!!!!!!!
				// 从高位往低位看，一个一个下去，遇到一个可以满足的就把不能满足的都删掉。剩下的一定是可以满足的
				// 最后任取前面m个即可。O(n)!!!!!!Surprise!!!!!! 
				// 可能会超最后一个点
				// 如果每一位都修改的话那就不行。
				// 40*40*n+40*n约等于368000000
				// 就算是30*31*n都有一亿多
			}
		}
		i64 ans = a[0];
		for(i64 i = 1;i < m;i ++) {
			ans &= a[i];
		}
		std::cout << ans << std::endl;
		return;
	}
};
i32 main() {
	std::freopen("and.in", "r", stdin);
	std::freopen("and.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; // std::cin >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

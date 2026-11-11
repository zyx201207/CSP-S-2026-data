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
	struct Node {
		i64 a; char c;
	};
	void solve() {
		i64 n, pref = 0LL, L = 0; std::cin >> n;
		std::vector<Node> a(n);
		std::vector<i64> st(n);
		for(i64 i = 0;i < n;i ++) {
			std::cin >> a[i].a >> a[i].c;
			st[i] = pref, pref += a[i].a;
			L += a[i].a;
		}
		i64 ans = 0LL;
		for(i64 i = 0;i < L;i ++) {
			i64 j = L - i - 1;
			i64 st1 = std::upper_bound(all(st), i) - st.begin() - 1;
			i64 st2 = std::upper_bound(all(st), j) - st.begin() - 1;
			if(a[st1].c != a[st2].c) ans ++;
		}
		std::cout << (ans >> 1) << "\n";
		return;
		// ´úÂëÃÀÈç»­£¡
	}
};
i32 main() {
	std::freopen("string.in", "r", stdin);
	std::freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; // std::cin >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

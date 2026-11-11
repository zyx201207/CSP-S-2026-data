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
		i64 c1; std::string s1; std::cin >> c1 >> s1;
		i64 c2; std::string s2; std::cin >> c2 >> s2;
		i64 lie1 = 0, lie2 = 0;
		for(char c : s1)
			if(isdigit(c)) lie1 = lie1 * 10 + c - '0';
		for(char c : s2)
			if(isdigit(c)) lie2 = lie2 * 10 + c - '0';
		std::vector<std::pair<char, char>> p;
		p = {mp('F', 'D'), mp('C', 'B'), mp('B', 'A'),
			 mp('D', 'F'), mp('B', 'C'), mp('A', 'B')};
		if(c1 == c2) {
			std::cout << "1";
			if(lie1 == lie2) {
				std::cout << "1";
				char ch1 = s1[2], ch2 = s2[2];
				if(ch1 > ch2) std::swap(ch1, ch2);
				if((ch1 == 'D' && ch2 == 'F') || (ch1 == 'A' && ch2 == 'B') || 
				   (ch1 == 'B' && ch2 == 'C') || (ch1 == 'A' && ch2 == 'C')) {
				   	std::cout << "1";
				   	if((ch1 == 'D' && ch2 == 'F') ||
					   (ch1 == 'A' && ch2 == 'B') ||
					   (ch1 == 'B' && ch2 == 'C'))
					   	std::cout << "1";
					else std::cout << "0";
				}
				else std::cout << "00";
				std::cout << "\n";
			}
			else std::cout << "000";
		}
		else std::cout << "0000";
		return;
	}
};
i32 main() {
	std::freopen("travel.in", "r", stdin);
	std::freopen("travel.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 tt = 1LL; // std::cin >> tt;
	while(tt --)
		I_AK_CNOI_CFR_ATC_RPPP::solve();
	return 0;
}

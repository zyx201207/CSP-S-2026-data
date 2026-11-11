//GZ-J00460 贵阳市第十七中学 徐廷蔚
#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	string ans = "";
	if(a1 != a2) {
		ans = "0000";
	} else {
		string tmp1 = "";
		tmp1.push_back(b1[0]);
		tmp1.push_back(b1[1]);
		string tmp2 = "";
		tmp2.push_back(b2[0]);
		tmp2.push_back(b2[1]);
		if(tmp1 == tmp2) {
			int check1 = 0,check2 = 0;
			char ch1 = b1[2];
			char ch2 = b2[2];
			if(ch1 == 'D' || ch1 == 'E') check1 = 1;
			if(ch2 == 'D' || ch2 == 'E') check2 = 1;
			if(check1 != check2) {
				ans = "1100";
			} else {
				if(check1 == 1) ans = "1111";
				if(check1 == 0) {
					int gap = ch1 - ch2;
					gap = abs(gap);
					if(gap == 1) ans = "1111";
					else ans = "1110";
				}
			}
		}
		else {
			ans = "1000";
		}	
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;

// RP++
// AC AC AC
// 图灵老祖助我一臂之力 
// 图灵保佑 
// 
//   o  o  o
//    o o o
//     ooo
//   --------
//  (        )
//   --------
// 
// 好无聊 (11:11) 
// dayz的time表太牢了 
// dayz class 850 的 ywb 和 js 是 (char)70 (char)101 (char)109 (char)98 (char)97 (char)121.

string a1, b1, a2, b2, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a1 >> b1 >> a2 >> b2;
	
	if (a1 == a2) {
		ans += "1";
	}
	else {
		ans += "0";
	}
	
	if (ans[0] == '1') {
		if (b1.substr(0, 2) == b2.substr(0, 2)) {
			ans += "1";
		}
		else {
			ans += "0";
		}
	}
	else {
		ans += "0";
	}
	
	if (ans[1] == '1') {
		if ('A' <= b1[2] && b1[2] <= 'C') {
			if ('A' <= b2[2] && b2[2] <= 'C') {
				ans += "1";
			}
			else {
				ans += "0";
			}
		}
		else {
			if ('D' <= b2[2] && b2[2] <= 'F') {
				ans += "1";
			}
			else {
				ans += "0";
			}
		}
	}
	else {
		ans += "0";
	}
	
	if (ans[2] == '1') {
		if (abs(b1[2]-b2[2]) == 1) {
			ans += "1";
		}
		else {
			ans += "0";
		}
	}
	else {
		ans += "0";
	}
	
	cout << ans << "\n";

	return 0;
}


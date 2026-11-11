// FJ-J00060
// 100pts
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool flag_tongchexiang = false, flag_tongyice = false, flag_tongyipai = false;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string res = "";
	if (c1 == c2) {
		flag_tongchexiang = true;
		res += "1";
	} else {
		res += "0";
	}
	if (flag_tongchexiang && s1[0] == s2[0] && s1[1] == s2[1]) {
		flag_tongyipai = true;
		res += "1";
	} else {
		res += "0";
	}
	if (flag_tongchexiang && flag_tongyipai && ((s1[2] == 'A' && s2[2] == 'B') ||
	                       (s1[2] == 'A' && s2[2] == 'C') ||
	                       (s1[2] == 'B' && s2[2] == 'C') ||
	                       (s2[2] == 'A' && s1[2] == 'B') ||
	                       (s2[2] == 'A' && s1[2] == 'C') ||
	                       (s2[2] == 'B' && s1[2] == 'C') ||
	                       (s1[2] == 'D' && s2[2] == 'F') ||
	                       (s1[2] == 'F' && s2[2] == 'D'))) {
		flag_tongyice = true;
		res += "1";
	} else {
		res += "0";
	}
	if (flag_tongchexiang && flag_tongyipai && flag_tongyice && ((s1[2] == 'A' && s2[2] == 'B') ||
	                      (s1[2] == 'B' && s2[2] == 'C') ||
	                      (s2[2] == 'A' && s1[2] == 'B') ||
	                      (s2[2] == 'B' && s1[2] == 'C') ||
	                      (s1[2] == 'D' && s2[2] == 'F') ||
	                      (s1[2] == 'F' && s2[2] == 'D')
	                     )) {
		res += "1";
	} else {
		res += "0";
	}
	cout << res;
	return 0;
}


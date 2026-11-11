#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string c1, s1, c2, s2, ans;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans += "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (s1[1] == s2[1] && s1[0] == s2[0]) {
		ans += "1";
	} else {
		ans += "0";
	}
	if (ans[1] == '1') {
		if (s1[2] <= 'C') {
			if (s2[2] <= 'C') {
				ans += "1";
			} else {
				ans += "0";
			}
		} else {
			if (s2[2] <= 'C') {
				ans += "0";
			} else {
				ans += "1";
			}
		}
	} else {
		ans += "0";
	} 
	if (ans[2] == '0') {
		ans += "0";
	} else {
		if (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1) {
			ans += "1";
		} else {
			ans += "0"; 
		}
	}
	cout << ans;
	return 0;
}

/*
02 01A 02 01B
1111

02 01C 02 01A
1110

02 01C 02 01D
1100

02 02B 02 01A
1000

02 01A 03 01A
0000
*/

#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const ll N = 1e6 + 10;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	ll c = c1[1] - '0' + (c1[0] - '0') * 10, cc = c2[1] - '0' + (c2[0] - '0') * 10, s = s1[1] - '0' + (s1[0] - '0') * 10, ss = s2[1] - '0' + (s2[0] - '0') * 10;
	string ans = "";
	if (c == cc) {
		ans = "1";
		if (s == ss) {
			ans = ans + "1";
			if (((s1[2] - 'A') <= 2 && (s2[2] - 'A') <= 2) || ((s1[2] - 'A') > 2 && (s2[2] - 'A') > 2)) {
				ans = ans + "1";
				if (abs((s1[2] - 'A') - (s2[2] - 'A')) == 1) ans = ans + "1";
				else ans = ans + "0"; 
			}else ans = ans + "00";
		} else ans = ans + "000";
	}
	else ans = "0000";
	cout << ans;
	return 0;
}

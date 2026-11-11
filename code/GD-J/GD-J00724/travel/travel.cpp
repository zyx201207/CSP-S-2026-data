#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
string ans;
int num[10] = {0, 1, 2, 10, 11};

signed main() {
	freopen("travle.in", "r", stdin);
	freopen("travle.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) {
		ans += '1';
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans += '1';
			if ((num[int(s1[2] - 'A')] <= 2 && num[int(s2[2] - 'A')] <= 2) || (num[int(s1[2] - 'A')] > 5 && num[int(s2[2] - 'A')] > 5)) {
				ans += '1';
				if (abs(num[int(s1[2] - 'A')] - num[int(s2[2] - 'A')]) == 1) ans += '1';
				else ans += '0';
			} else ans += "00";
		} else ans += "000";
	} else ans = "0000";
	cout << ans << endl;
	return 0;
} 

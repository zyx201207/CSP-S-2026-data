#include<bits/stdc++.h>
using namespace std;
int main (  ) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, ans = "";
	cin >> c1 >> s1 >> c2 >> s2;
	int cnt = s1.size(), sum = s2.size();
	char a = s1[cnt - 1], b = s2[sum - 1];
	ans += (c1 == c2) ? '1' : '0';
	if(ans[0] == '0') {
		cout << ans << "000";
		return 0;
	}
	ans += (s1.substr(0, 2) == s2.substr(0, 2)) ? '1' : '0';
	if(ans[1] == '0') {
		cout << ans << "00";
		return 0;
	}
	ans += ((a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C') || ((a == 'D' || a == 'F') && (b == 'D' || b == 'F'))) ? '1' : '0';
	if(ans[2] == '0') {
		cout << ans << '0';
		return 0;
	}
	ans += ((abs(a - '0' - (b - '0')) == 1) || (a == 'D' && b == 'F') || (a == 'F' && b == 'D')) ? '1' : '0';
	cout << ans;
	return 0;
}

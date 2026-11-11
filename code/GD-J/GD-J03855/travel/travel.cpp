#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	string ans;
	if(c1 == c2) {
		ans += '1';
	} else {
		ans += '0';
	}
	if(s1[0] + s1[1] == s2[0] + s2[1]) {
		ans += '1';
	} else {
		ans += '0';
	}
	if(s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' && s2[2] >= 'D') {
		ans += '1';
		if(s1[2] == s2[2] + 1 || s2[2] == s1[2] + 1) {
			ans += '1';
		} else {
			ans += '0';
		}
	} else {
		ans += '0';
		ans += '0';
	}
	cout << ans;
	return 0;
}

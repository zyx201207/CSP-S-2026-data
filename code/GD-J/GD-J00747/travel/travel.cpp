#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int a;
	string c1, s1, c2, s2, ans = "";
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) ans += '1';
	else {
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) ans += '1';
	else {
		cout << ans << "000";
		return 0;
	}
	if(s1[2] <= 'C' && s2[2] <= 'C') {
		ans += '1';
		a = 0;
	} else if(s1[2] >= 'D' && s2[2] >= 'D') {
		ans += '1';
		a = 1;
	} else ans += '0';
	if(ans == "111") {
		if(a == 0 && abs(s1[2] - s2[2]) == 1) ans += '1';
		else if(a == 1 && abs(s1[2] - s2[2]) == 2) ans += '1';
		else ans += '0';
	}
	else ans += '0'; 
	cout << ans << '\n';

	return 0; 
} 

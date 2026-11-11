#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, r1, c2, r2;
	cin >> c1 >> r1 >> c2 >> r2;
	
	string ans = "";
	if(c1 == c2)  {
		ans += '1';
		if(r1[0] == r2[0] && r1[1] == r2[1]) {
			ans += '1';
			if((r1[2] == 'D' || r1[2] == 'F') && (r2[2] == 'D' || r2[2] == 'F') || (r1[2] != 'D' && r1[2] != 'F') && r2[2] != 'D' && r2[2] != 'F') {
				ans += '1';
				if(abs(r1[2] - r2[2]) == 1) ans += '1';
				else ans += '0';
			} else ans += "00";
		}
		else ans += "000";
	}
	else ans = "0000";
	
	cout << ans;
}

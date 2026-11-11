#include <bits/stdc++.h>
using namespace std;
#define int long long

string c1, s1, c2, s2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000" << '\n';
		return 0;
	}
	cout << '1';
	for(int i = 0; i < 2; i ++) {
		if(s1[i] != s2[i]) {
			cout << "000" << '\n';
			return 0;
		}
	}
	cout << '1';
	if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A')) cout << '1' << '1';
	else if((s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'A' && s2[2] == 'C')) cout << '1' << '0';
	else if((s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C')) cout << '1' << '1';
	else if((s1[2] == 'D' && s2[2] == 'E') || (s1[2] == 'E' && s2[2] == 'D')) cout << '1' << '1';
	else cout << '0' << '0';
	
	return 0;
} 

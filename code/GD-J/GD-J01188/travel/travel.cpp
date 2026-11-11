#include<bits/stdc++.h>

using namespace std;
string c1, s1, c2, s2, n = "0000";

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {  // 感觉用switch也更好 
		n[0] = '1';
	}
	if(n[0] == '1' && s1[0] == s2[0] && s2[1] == s2[1]) {
		n[1] = '1';
	}
	if(n[1] == '1' && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))) {
		n[2] = '1';
	}
	if(n[2] == '1' && abs(int(s1[2]) - int(s2[2])) == 1) {
		n[3] = '1';
	}
	cout << n << "\n";
	return 0;
} 

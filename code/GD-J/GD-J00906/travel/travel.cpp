#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 0 + 10;
string c, s, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> c >> s >> c2 >> s2;
	if (c == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (s.substr(0, 2) == s2.substr(0, 2)) cout << 1;
	else cout << 0;
	if ( s.substr(0, 2) == s2.substr(0, 2) && ( 
	((s.substr(2, 1) == "F" || s.substr(2, 1) == "D") && 
	(s2.substr(2, 1) == "F" || s2.substr(2, 1) == "D")) 
	|| 
	((s.substr(2, 1) != "F" && s.substr(2, 1) != "D") && 
	(s2.substr(2, 1) != "F" && s2.substr(2, 1) != "D"))) ) cout << 1;
	else cout << 0;
	char k = s[2], k2 = s2[2];
	if ( s.substr(0, 2) == s2.substr(0, 2) && (
	((s.substr(2, 1) == "F" || s.substr(2, 1) == "D") && 
	(s2.substr(2, 1) == "F" || s2.substr(2, 1) == "D")) || 
	((s.substr(2, 1) != "F" && s.substr(2, 1) != "D") && 
	(s2.substr(2, 1) != "F" && s2.substr(2, 1) != "D")) && c == c2 && 
	s.substr(0, 2) == s2.substr(0, 2) && abs(k - k2) < 2)) cout << 1;
	else cout << 0;
	return 0;
} 

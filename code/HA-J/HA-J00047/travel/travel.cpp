#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
string c1, s1, c2, s2;
bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) f1 = 1;
	if (f1 && (s1[0] == s2[0]) && (s1[1] == s2[1])) f2 = 1;
	if (f2) {
		if (s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D') {
			f3 = 1;
		} else if (s1[2] != 'D' && s1[2] != 'F' && s2[2] != 'D' && s2[2] != 'F') {
			f3 = 1;
		} else {
			f3 = 0;
		}
	} 
	if (f3 && abs(s1[2] - s2[2]) == 1) f4 = 1;
	if (f1) cout << 1;
	else cout << 0;
	if (f2) cout << 1;
	else cout << 0;
	if (f3) cout << 1;
	else cout << 0;
	if (f4) cout << 1;
	else cout << 0;
	return 0;
}

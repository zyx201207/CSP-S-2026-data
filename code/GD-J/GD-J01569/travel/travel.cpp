#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
map<char, int> mp;
map<char, int> side;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	mp['A'] = 1, mp['B'] = 2, mp['C'] = 3, mp['D'] = 5, mp['E'] = 6;
	side['A'] = 1, side['B'] = 1, side['C'] = 1, side['D'] = 2, side['E'] = 2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if (side[s1[2]] == side[s2[2]]) {
				cout << "1";
				if (abs(mp[s1[2]] - mp[s2[2]]) == 1) {
					cout << "1";
				} else {
					cout << "0\n";
				}
			}else {
				cout << "00\n";
			}
		}else {
			cout << "000\n";
		}
	}else {
		cout << "0000\n";
	}
	return 0;
}

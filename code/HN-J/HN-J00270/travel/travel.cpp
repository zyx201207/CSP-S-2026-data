#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
	
	bool sameRoom = (c1 == c2),
		 sameRow  = (s1[0] == s2[0] && s1[1] == s2[1])
		 			&& sameRoom,
		 sameSide = !(s1.back() <= 'C' ^ s2.back() <= 'C')
			   		&& sameRow;
	cout << sameRoom << sameRow << sameSide << (sameSide && abs(s1.back() - s2.back()) == 1);
	return 0;
}

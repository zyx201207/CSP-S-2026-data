#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool side() {
	char as = s1[2];
	char bs = s2[2];
	string l = "ABC";
	string r = "DF";
	int m = 1;
	for (char i : l) {
		m ^= (as == i);
		m ^= (bs == i);
	}
	return m && (s1.substr(0, 2) == s2.substr(0, 2)) && (c1 == c2);
}

bool near() {
	bool r = false;
	char as = s1[2];
	char bs = s2[2];
	if (as == 'B' && (bs == 'A' || bs == 'C')) r = true;
	if (bs == 'B' && (as == 'A' || as == 'C')) r = true;
	if (as == 'D' && bs == 'F') r = true;
	if (bs == 'D' && as == 'F') r = true;
	return r && (s1.substr(0, 2) == s2.substr(0, 2)) && (c1 == c2);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin  >> c1 >> s1 >> c2 >> s2;
	cout << int(c1 == c2);
	cout << int(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2));
	cout << side();
	cout << near() << endl;
	return 0;
}
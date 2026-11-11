#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string h1,h2;
char p1,p2;
bool dir(char c) {
	if (c == 'A' || c == 'B' || c == 'C') return 0;
	return 1;
}
bool con(char a,char b) {
	if (a == 'A' && b == 'B') return 1;
	if (a == 'B' && b == 'A') return 1;
	if (a == 'B' && b == 'C') return 1;
	if (a == 'C' && b == 'B') return 1;
	if (a == 'D' && b == 'F') return 1;
	if (a == 'F' && b == 'D') return 1;
	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	h1 = s1.substr(0,2);p1 = s1[2];
	h2 = s2.substr(0,2);p2 = s2[2];
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (c1 == c2 && h1 == h2) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (c1 == c2 && h1 == h2 && dir(p1) == dir(p2)) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (c1 == c2 && h1 == h2 && dir(p1) == dir(p2) && con(p1,p2)) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}

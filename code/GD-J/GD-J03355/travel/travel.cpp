#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1!=c2) {
		cout << "0000" << endl;
		return 0;
	}
	cout << 1;
	if (s1[0]!=s2[0]||s1[1]!=s2[1]) {
		cout << "000" << endl;
		return 0;
	}
	cout << 1;
	if ((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')) {
		cout << "00" << endl;
		return 0;
	} else if ((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')) {
		cout << "00" << endl;
		return 0;
	}
	cout << 1;
	char a, b;
	a=min(s1[2], s2[2]);
	b=max(s1[2], s2[2]);
	if ((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}

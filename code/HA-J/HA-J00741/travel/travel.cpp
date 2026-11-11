#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	}else {
		cout << "0000";
		return 0;
	}//first
	string a = "", b = "";
	for (int i = 0; i <= 1; i ++) {
		a += s1[i];
		b += s2[i];
	}
	if (a == b) {
		cout << 1;
	}else {
		cout << "000";

		return 0;
	}//second
	char c = s1[2], d = s2[2];
	if ((c == 'D' && d != 'F') || (c == 'F' && d != 'D') || (d == 'D' && c != 'F') || (d == 'F' && c != 'D')) {
		cout << "00";
		return 0;
	}else {
		cout << 1;
	}//third
//	if (s2[0] == s1[0] && s2[1] == s1[1]) {
//		if (s[])
//	}
//	if (s2[0] == '0') {
//		if (s1[1] + 1 == 2 || s1[1] == s2[1] || s1[1] - 1 == s2[1]) {
//			cout << 1 << endl;
//		}else {
//			cout << '0' << endl;
//		}
//	}else {
//		if (s1 == s2 || s1[1] + 1 == s2[1] || s1[1] - 1 == s2[1]) {
//			cout << 1 << endl;
//		}else {
//			cout << '0' << endl;
//		}
//	}
	if (s1[2] == s2[2]) {
//		string a = a + s1[0] + s1[2];
//		string b = b + s2[0] + s2[2];
		if (a[0] != b[0]) cout << '0';
		else if (a[1] + 1 != b[1] && a[1] - 1 != b[1]) cout << '0';
		else cout << 1;
	}else {
		if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2] && (!(s1[2] == 'C' && s2[2] == 'D') && (!(s1[2] == 'D' && s2[2] == 'C')))) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}






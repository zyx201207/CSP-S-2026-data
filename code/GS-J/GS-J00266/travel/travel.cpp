#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	int n1 = (s1[0] - '0') * 10 + s1[1] - '0'; 
	int n2 = (s2[0] - '0') * 10 + s2[1] - '0'; 
	if (n1 != n2) {
		cout << "000";
		return 0;
	}
	cout << "1";
	char t1 = s1[2], t2 = s2[2];
	if (t1 == 'A' && t2 == 'D' || t1 == 'A' && t2 == 'F' || t1 == 'B' && t2 == 'D' || t1 == 'B' && t2 == 'F' || t1 == 'C' && t2 == 'D' || t1 == 'C' && t2 == 'F') {
		cout << "00";
		return 0;
	}
	if (t2 == 'A' && t1 == 'D' || t2 == 'A' && t1 == 'F' || t2 == 'B' && t1 == 'D' || t2 == 'B' && t1 == 'F' || t2 == 'C' && t1 == 'D' || t2 == 'C' && t1 == 'F') {
		cout << "00";
		return 0;
	}
	cout << "1";
	if (t1 == 'A' && t2 == 'B' || t1 == 'B' && t2 == 'A' || t1 == 'B' && t2 == 'C' || t1 == 'C' && t2 == 'B' || t1 == 'D' && t2 == 'F' || t1 == 'F' && t2 == 'D') {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}

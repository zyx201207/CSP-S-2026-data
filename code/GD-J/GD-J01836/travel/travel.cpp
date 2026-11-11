#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
char f = '0', t = '1';
bool flag = false;
int a1, b1, a2, b2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << t;
		flag = true;
	}
	else{
		cout << f;
	}
	if (flag && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << t;
	} else {
		cout << f;
		flag = false;
	}
	if (flag) {
		if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') {
			cout << t;
		} else if (s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E') {
			cout << t;
		} else {
			cout << f;
		}
	} else {
		cout << f;
	}
	a1 = (s1[0] - '0') * 10 + s1[1] - '0';
	b1 = s1[2] - 'A';
	a2 = (s2[0] - '0') * 10 + s2[1] - '0';
	b2 = s2[2] - 'A';
	if ((abs(a1 - a2) == 1 && b1 == b2) || a1 == a2 && abs(b1 - b2) == 1) {
		if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') {
			cout << t;
		} else if (s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E') {
			cout << t;
		} else {
			cout << f;
		}
	} else {
		cout << f;
	}
	return 0;
} 

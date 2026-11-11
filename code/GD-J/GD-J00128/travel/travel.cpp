#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool check (char qqq) {
	if (qqq >= 'D') {
		return true;
	}
	return false;
}

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> s1 >> s2;
	if (c1 == s1) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if (c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1]) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if (c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1] && check(c2[2]) == check(s2[2])) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if (c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1] && check(c2[2]) == check(s2[2]) && abs(s2[2] - c2[2]) == 1) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

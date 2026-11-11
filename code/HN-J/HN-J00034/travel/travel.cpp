#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


string s1, s2;
int n1, n2;
int m1, m2;
int k1, k2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	AC;
	cin >> n1 >> s1 >> n2 >> s2;
	//³µÏá ×ùÎ»ºÅ
	if (n1 == n2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	m1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	m2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (s1[2] == 'A') {
		k1 = 1;
	}
	else if (s1[2] == 'B') {
		k1 = 2;
	}
	else if (s1[2] == 'C') {
		k1 = 3;
	}
	else if (s1[2] == 'D') {
		k1 = 4;
	}
	else if (s1[2] == 'F') {
		k1 = 5;
	}
	
	if (s2[2] == 'A') {
		k2 = 1;
	}
	else if (s2[2] == 'B') {
		k2 = 2;
	}
	else if (s2[2] == 'C') {
		k2 = 3;
	}
	else if (s2[2] == 'D') {
		k2 = 4;
	}
	else if (s2[2] == 'F') {
		k2 = 5;
	}
	if (m1 == m2) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if (k1 <= 3 && k2 <= 3) {
		cout << 1;
	}
	else if (k1 >= 4 && k2 >= 4) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if (k2 < k1) swap(k1, k2);
	if (k1 == 1 && k2 == 2) {
		cout << 1;
	}
	else if (k1 == 2 && k2 == 3) {
		cout << 1;
	}
	else if (k1 == 4 && k2 == 5) {
		cout << 1;
	}
	else cout << 0;
	
	return 0;
}
//Trick||Treat!


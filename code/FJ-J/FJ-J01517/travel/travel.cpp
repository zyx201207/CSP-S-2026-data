#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string a1, b1;
	cin >> a >> a1 >> b >> b1;
	string s1 = "";
	s1 += a1[0];
	s1 += a1[1];
	string s2 = "";
	s2 += b1[0];
	s2 += b1[1];
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	if (a == b) {
		cout << 1;
		if (s1 == s2) {
			cout << 1;
			if ('A' <= a1[2] && a1[2] <= 'C') {
				flag1 = 1;
			}
			if ('A' <= b1[2] && b1[2] <= 'C') {
				flag2 = 1;
			} 
			if (flag1 == flag2) {
				cout << 1;
				if (a1[2] < b1[2]) {
					flag3 = 1;
				}
				if (flag3 == 1) {
					if (b1[2] - a1[2] == 1) {
						cout << 1;
					}
					else {
						cout << 0;
					}
				}
				else {
					if (a1[2] - b1[2] == 1) {
						cout << 1;
					}
					else {
						cout << 0;
					}
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}

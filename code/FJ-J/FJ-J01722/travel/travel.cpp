#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 10;
string c1, c2, c3, c4;
bool check1() {
	char ch1 = c2[2];
	char ch2 = c4[2];
	if (ch1 == 'E' && ch2 == 'F') return true;
	if (ch1 == 'F' && ch2 == 'E') return true;
	//
	if (ch1 == 'A' && ch2 == 'B') return true;
	if (ch1 == 'B' && ch2 == 'A') return true;
	if (ch1 == 'A' && ch2 == 'C') return true;
	if (ch1 == 'C' && ch2 == 'A') return true;
	if (ch1 == 'B' && ch2 == 'C') return true;
	if (ch1 == 'C' && ch2 == 'B') return true;
	return 0;
}
bool check2() {
	char ch1 = c2[2];
	char ch2 = c4[2];
	if (ch1 == 'E' && ch2 == 'F') return true;
	if (ch1 == 'F' && ch2 == 'E') return true;
	//
	if (ch1 == 'A' && ch2 == 'B') return true;
	if (ch1 == 'B' && ch2 == 'A') return true;
	//
	if (ch1 == 'B' && ch2 == 'C') return true;
	if (ch1 == 'C' && ch2 == 'B') return true;
	return 0;
}
signed main() {
	freopen("travel.in", "r" ,stdin);
	freopen("travel.out", "w" ,stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == c3) {
		cout << "1";
		if (c2[0] == c4[0] && c2[1] == c4[1]) {
			cout << "1";
			if (check1()) {
				cout << "1";
				if (check2()) {
					cout << "1";
				}
				else {
					cout << "0";
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

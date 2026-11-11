#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) {
		cout << 1;
		c1 = (s1[0] - '0') * 10 + s1[1] - '0', c2 = (s2[0] - '0') * 10 + s2[1] - '0';
		if(c1==c2) {
			cout << 1;
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
				if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
					cout << 1;
					int diff = s1[2] - s2[2];
					if(diff == 1 || diff == -1) {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << "00";
				}
			} else {
				if(s2[2] == 'D' || s2[2] == 'F') {
					cout << 1;
					int diff = s1[2] - s2[2];
					if(diff == 2 || diff == -2) {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << "00";
				}
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	fclose(stdin), fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

string c_1, s_1, c_2, s_2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if(c_1 == c_2) {
		cout << "1";
		string str_1 = s_1.substr(0, 2);
		string str_2 = s_2.substr(0, 2);
		if(str_1 == str_2) {
			cout << "1";
			if(s_1[2] >= 'A' && s_1[2] <= 'C' && s_2[2] >= 'A' && s_2[2] <= 'C') {
				cout << "1";
				if(s_1[2] == 'A') {
					if(s_2[2] == 'B') {
						cout << "1" << '\n';
					}
					else {
						cout << "0" << '\n';
					}
				}
				else if(s_1[2] == 'B') {
					cout << "1" << '\n';
				}
				else {
					if(s_2[2] == 'B') {
						cout << "1" << '\n';
					}
					else {
						cout << "0" << '\n';
					}
				}
			}
			else if(s_1[2] >= 'D' && s_1[2] <= 'F' && s_2[2] >= 'D' && s_2[2] <= 'F') {
				cout << "11" << '\n';
			}
			else {
				cout << "00" << '\n';
			}
		}
		else {
			cout << "000" << '\n';
		}
	}
	else {
		cout << "0000" << '\n';
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			switch(s1[2]) {
				case 'A':
				case 'B':
				case 'C':
				{
					if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
						cout << 1;
						if(s1[2] == 'B' || s2[2] == 'B') cout << 1;
							else cout << 0;
					}else {
						cout << "00";
					}
					break;
				}
				case 'D':
				case 'F':
				{
					if(s2[2] == 'D' || s2[2] == 'F') {
						cout << "11";
					}else {
						cout << "00";
					}
					break;
				}
			}
		}else {
			cout << "000";
		}
	}else {
		cout << "0000";
	}
	cout << '\n';
	return 0;
}


#include<bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) cout << "0000" << endl;
	else {
		cout << "1";
		string y1 = "", y2 = "";
		y1 += s1[0], y1 += s1[1];
		y2 += s2[0], y2 += s2[1];
		if(y1 != y2) cout << "000" << endl;
		else {
			cout << "1";
			char x1 = s1[2], x2 = s2[2];
			if(x1 >= 'D' && x2 >= 'D') {
				cout << "11" << endl;
			}
			else if(x1 <= 'C' && x2 <= 'C') {
				cout << "1";
				if(abs(int(x1 - x2)) == 1) {
					cout << "1" << endl;
				}
				else {
					cout << "0" << endl;
				}
			}
			else {
				cout << "00" << endl;
			}
		}
	}
	
	return 0;
}

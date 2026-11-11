#include <bits/stdc++.h>

using namespace std;

int ff(char s);

int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string cr, rr, cs, rs;
	cin >> cr >> cs >> rr >> rs;
	if (cr != rr) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (cs[0] == rs[0] && cs[1] == rs[1]) {
		cout << "1";
		if (ff(cs[2]) == ff(rs[2])) {
			cout << "1";
			if (abs(int(cs[2] - 'A') - int(rs[2] - 'A')) == 1) 
				cout << "1";
			else cout << "0";
		}
		else cout << "00";
		
	} else 	
		cout << "000";
	return 0;
} 

int ff(char s) {
	switch(s) {
		case 'A' : case 'B' : case 'C' : return 1;
		default : return 2;
	}
}

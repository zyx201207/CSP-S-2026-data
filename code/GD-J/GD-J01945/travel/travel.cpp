#include <bits/stdc++.h>
#define int long long

using namespace std;

string a1, b1, a2, b2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a1 >> b1 >> a2 >> b2;
	
	char c1 = b1[2], c2 = b2[2];
	string s1, s2;
	s1 = s2 = "";
	for(int i = 0; i <= 1; i ++) {
		s1 = s1 + b1[i];
		s2 = s2 + b2[i];
	}
	
	if(a1 == a2) {
		cout << "1";
		if(s1 == s2) {
			cout << "1";
			if(!((c1 <= 'C' && c2 >= 'D') || (c1 >= 'D' && c2 <= 'C'))) {
				cout << "1";
				if(abs(c1 - c2) == 1) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	}  else {
		cout << "0000";
	}
	return 0;
} 

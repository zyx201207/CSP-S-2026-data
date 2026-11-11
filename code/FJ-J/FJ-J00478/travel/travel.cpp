#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
char z1, z2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	z1 = s1[2];
	s1[2] = ' ';
	z2 = s2[2];
	s2[2] = ' ';
	if(c1 == c2) {
		cout << 1;
		if(s1 == s2) {
			cout << 1;
			if((z1 == 'D' && z2 == 'F') || (z1 == 'F' && z2 == 'D')) {
				cout << "11";
				return 0;
			}
			if((z1 == 'D' && (z2 == 'A' || z2 == 'B' || z2 == 'C')) || (z1 == 'F' && (z2 == 'A' || z2 == 'B' || z2 == 'C'))) {
				cout << "00";
				return 0;
			}
			if((z2 == 'D' && (z1 == 'A' || z1 == 'B' || z1 == 'C')) || (z2 == 'F' && (z1 == 'A' || z1 == 'B' || z1 == 'C'))) {
				cout << "00";
				return 0;
			}
			if((z1 == 'A' && z2 == 'C') || (z1 == 'C' && z2 == 'A')) {
				cout << "10";
				return 0;
			}
			cout << "11";
		}
		else {
			cout << "000";
			return 0;
		}
	}
	else {
		cout << "0000";
		return 0;
	}
	return 0;
}


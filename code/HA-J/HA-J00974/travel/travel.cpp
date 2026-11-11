#include <bits/stdc++.h>
using namespace std;

string c1 , s1 , c2 , s2;
string ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0]  == c2[0] && c1[1] == c2[1]) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	if(s1[0] != s2[0] && s2[1] != s2[1]) {
		cout << "000";
		return 0;
	} else {
		cout << "1";
	}
	if((s1[2] > 'C' && s2[2] > 'C') || (s1[2] < 'D' && s2[2] < 'D')) {
		cout << "1";
		if((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A')) {
				cout << "0";
				return 0;
			} else {
				cout << "1";
			}
	} else {
		cout << "00";
		return 0;
	}
	
	return 0;
}

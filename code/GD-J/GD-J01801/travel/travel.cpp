#include <bits/stdc++.h>
using namespace std;
int yes[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1, s1, c2, s2;
	
	if (c1 == c2) {
		yes[1] = '1';
	}
	else {
		yes[1] = '0';
	}
	if (yes[1] == '1' && s1[0]==s2[0] && s1[1]==s2[1]) {
		yes[2] = '1';
	}
	else {
		yes[2] = '0';
	}
	if (yes[2] == '1') {
		if (s1[2]=='A'||s1[2]=='B'||s1[2]=='C') {
			if (s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
				yes[3] = '1';
			}
			else {
				yes[3] = '0';
			}
		}
		else {
			if (s2[2]=='D'||s2[2]=='F') {
				yes[3] = '1';
			}
			else {
				yes[3] = '0';
			}
		}
	}
	else {
		yes[3] = '0';
	}
	if (yes[3] == '1') {
		if (s2[2]=='D'||s2[2]=='F') {
			yes[4] = '1';
		}
		else if ((s1[2]-s2[2]==1)||(s2[2]-s2[2]==1)) {
				yes[4] = '1';
		}
		else {
			yes[4] = '0';
		}
	}
	else {
		yes[4] = '0';
	}
	for(int i=1; i<=4; i++) {
		cout << yes[i];
	}
	
	return 0;
}
 

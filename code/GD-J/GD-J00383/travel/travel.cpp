#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int b = 0;
	int f = 0;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		b = 1;
	}
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	string nps1 = "  ",nps2 = "  ";
	nps1[0] = s1[0];
	nps1[1] = s1[1];
	nps2[0] = s2[0];
	nps2[1] = s2[1];
	if (nps1 == nps2 && b) {cout << 1;f = 1;}
	if (nps1 != nps2) cout << 0;
	//02 02B 02 01A
	//cout << nps1 << " " << nps2 << endl;
	char pc1,pc2;
	pc1 = s1[2];
	pc2 = s2[2];
	if (((pc2 >= 'A' && pc2 <= 'C' && pc1 >= 'A' && pc2 <= 'C') || (pc2 >= 'D' && pc2 <= 'E' && pc1 >= 'D' && pc2 <= 'E')) && f && b) {
		cout << 1;
	}
	else cout << 0;
	char x1,x2;
	x1 = s1[2];
	x2 = s2[2];
	if (x1 >= 'A' && x1 <= 'C' && x2 >= 'A' && x2 <= 'C' && f && b) {
		if (x1 + 1 == x2 || x2 + 1 == x1) {
			cout << 1;
		}
		else cout << 0;
	}
	else if (x1 >= 'D' && x1 <= 'E' && x2 >= 'D' && x2 <= 'E' && f && b) {
		if (x1 + 1 == x2 || x2 + 1 == x1) {
			cout << 1;
		}
		else cout << 0;
	}
	else cout << 0;
//	cout << endl << endl;
	//cout << nps1 << " " << nps2 << endl;
	//02 01A 03 01A
} 

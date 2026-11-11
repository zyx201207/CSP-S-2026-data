#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

void cmp(string x, string y) {
	if (x[2] == 'A' || x[2] == 'B' || x[2] == 'C') {
		if (y[2] == 'D' || y[2] == 'F') {
			cout << "00";
		}else {
			cout << '1';
			if (abs(int(x[2]) - int(y[2])) == 1) cout << '1';
			else cout << 0;
		}
	}else {
		if (y[2] == 'A' || y[2] == 'B' || y[2] == 'C') cout << "00";
		else cout << "11";
	}
	return ;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}else {
		cout << '1';
		bool flag = 1;
		for(int i = 0; i < 2; i ++) if (s1[i] != s2[i]) {
			flag = 0;
		}		
		if (!flag) {
			cout << "000";
			return 0;
		}else {
			cout << '1';
			cmp(s1,s2);
		}
	}
	return 0;
}

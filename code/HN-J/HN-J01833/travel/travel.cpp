#include <bits/stdc++.h>
using namespace std;
string c,c1,c2,c3;
bool f;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> c1 >> c2 >> c3;
	if(c != c2) {
		cout << "0000" << endl;
		return 0;
	}
	for(int i = 0; i < 2; i++) {
		if(c1[i] != c3[i]) f = 1;
	}
	if(f) {
		cout << "1000" << endl;
		return 0;
	}
	int lenc = c1.size();
	int lenc1 = c3.size();
	if((c1[lenc - 1] <= 'C' && c3[lenc1 - 1] >= 'D') || (c3[lenc1 - 1] <= 'C' && c1[lenc - 1] >= 'D')) {
		cout << "1100" << endl;
		return 0;
	}
	if(abs(c1[lenc - 1] - c3[lenc1 - 1]) != 1) {
		cout << "1110" << endl;
		return 0;
	}
	cout << "1111" << endl;
	return 0;
} 


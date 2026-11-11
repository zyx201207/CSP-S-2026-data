#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string xiang1, xiang2, wei1, wei2;
	cin >> xiang1 >> wei1 >> xiang2 >> wei2;
	if (xiang1 == xiang2) {
		cout << "1";
		if (wei1.substr(0, 2) == wei2.substr(0, 2)) {
			cout << "1";
			if ((wei1[2] <= 'C' && wei2[2] <= 'C') || (wei1[2] > 'C' && wei2[2] > 'C')) {
				cout << "1";
				if (abs(int(wei1[2]) - int(wei2[2])) == 1) {
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
	} else {
		cout << "0000";
	}
	
	return 0;
}


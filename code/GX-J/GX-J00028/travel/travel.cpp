#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3) {	// tong che
		cout << "1";
		if((c2[0] + c2[1]) == (c4[0] + c4[1])) { // tong pai
			cout << "1";
			if((c2[2] == 'C' and c4[2] == 'D') or (c4[2] == 'C' and c2[2] == 'D')) {
					cout << "00";
					return 0;
			}
			else if(c4[2] - c2[2] > 2 or c4[2] - c2[2] < -2) { // tong ce
				cout << "00";
				return 0;
			}
			else { // xiang lin
				cout << "1";
				if((c2[2] == 'C' and c4[2] == 'D') or (c4[2] == 'C' and c2[2] == 'D')) {
					cout << "0";
					return 0;
				}
				else if(c4[2] - c2[2] == 1 or c4[2] - c2[2] == -1) {
					cout << "1";
					return 0;
				}
				else cout << "0";
			}
		}
		else {
			cout << "000";
			return 0;
		}
	}else cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string cfir, sfir, csec, ssec;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cfir >> sfir >> csec >> ssec;
	cout << (cfir == csec ? 1 : 0);
	if(cfir == csec) {
		cout << (sfir[0] == ssec[0] && sfir[1] == ssec[1] ? 1 : 0);
		if(sfir[0] == ssec[0] && sfir[1] == ssec[1]) {
			cout << (sfir[2] == 'A' && ssec[2] == 'B' || sfir[2] == 'A' && ssec[2] == 'C' || sfir[2] == 'B' && ssec[2] == 'C' || sfir[2] == 'B' && ssec[2] == 'A' || sfir[2] == 'C' && ssec[2] == 'B' || sfir[2] == 'C' && ssec[2] == 'A' || sfir[2] == 'D' && ssec[2] == 'F' || sfir[2] == 'F' && ssec[2] == 'D' ? 1 : 0);
			if(sfir[2] == 'A' && ssec[2] == 'B' || sfir[2] == 'A' && ssec[2] == 'C' || sfir[2] == 'B' && ssec[2] == 'C' || sfir[2] == 'B' && ssec[2] == 'A' || sfir[2] == 'C' && ssec[2] == 'B' || sfir[2] == 'C' && ssec[2] == 'A' || sfir[2] == 'D' && ssec[2] == 'F' || sfir[2] == 'F' && ssec[2] == 'D') {
				cout << (sfir[2] == 'A' && ssec[2] == 'B' || sfir[2] == 'B' && ssec[2] == 'A' || sfir[2] == 'B' && ssec[2] == 'C' || sfir[2] == 'C' && ssec[2] == 'B' || sfir[2] == 'D' && ssec[2] == 'F' || sfir[2] == 'F' && ssec[2] == 'D' ? 1 : 0);
			}else cout << "0";
		}else cout << "00";
	}else cout << "000";
	return 0;
}

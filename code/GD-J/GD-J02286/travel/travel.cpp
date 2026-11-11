#include <bits/stdc++.h>
using namespace std;
string ca, cb, cc, cd;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ca >> cb >> cc >> cd;
	if (ca == cc) {
		if ((cb[0] - '0') * 10 + cb[1] == (cd[0] - '0') * 10 + cd[1]) {
			if (cb[2] - 'A' < 3 && cd[2] - 'A' < 3) {
				if ((cb[2] == 'A' && cd[2] == 'C') || (cb[2] == 'C' && cd[2] == 'A')) cout << "1110";
				else cout << "1111";
			}
			else if (cb[2] - 'A' > 2 && cd[2] - 'A' > 2) cout << "1111";
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}


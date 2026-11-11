#include<bits/stdc++.h>
using namespace std;
string rc, rs, xc, xs;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rc >> rs >> xc >> xs;
	if (rc == xc) {
		if (rs[0] == xs[0] && rs[1] == xs[1]) {
			if (rs[2] >= 'D' && xs[2] >= 'D' || rs[2] <= 'C' && xs[2] <= 'C') {
				if ((int)(abs(rs[2] - xs[2])) == 1) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}

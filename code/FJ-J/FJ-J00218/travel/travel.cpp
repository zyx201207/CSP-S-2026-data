#include <bits/stdc++.h>
using namespace std;
string a, b, a1, b1;
bool ist = 0, isp = 0, isc = 0, isl = 0;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> a1 >> b >> b1;
	if(a == b) {
		ist = 1;
		if(a1[0] == b1[0] && a1[1] == b1[1]) {
			isp = 1;
			if(a1[2] < 'D' && b1[2] < 'D') {
				isc = 1;
				int aa = a1[2] - 'A', bb = b1[2] - 'A';
				if((aa - bb) * (bb - aa) == -1) isl = 1;
			}
			if(a1[2] > 'C' && b1[2] > 'C') {
				isc = 1;
				isl = 1;
			}
		}
	}
	cout << ist << isp << isc << isl;
	return 0;
}

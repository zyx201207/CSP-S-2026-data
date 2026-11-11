#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string r1, r2, x1, x2;
	cin >> r1 >> r2 >> x1 >> x2;
	bool flag;
	if (r1[0] == x1[0] && r1[1] == x1[1]) {
		flag = true;
	} else {
		flag = false;
	}
	if (flag == false) {
		cout << "0000" << endl;
	} else {
		if (r2[0] == x2[0] && r2[1] == x2[1]) {
			flag = true;
		} else {
			flag = false;
		}
		if (flag == false) {
			cout << "1000" << endl;
		} else {
			int rr, xx;
			if (r2[2] == 'A' || r2[2] == 'B' || r2[2] == 'C') {
				rr = 1;
			} else {
				rr = 2;
			}
			if (x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C') {
				xx = 1;
			} else {
				xx = 2;
			}
			if (rr != xx) {
				cout << "1100" << endl;
			} else {
				int rs, xs;
				rs = r2[2] - 'A';
				xs = x2[2] - 'A';
				if (abs(xs - rs) != 1) {
					cout << "1110" << endl;
				} else {
					cout << "1111" << endl;
				}
			}
		}
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
string cr, cx;
char sr[3], sx[3];
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
	cin >> cr;
	for(int i = 0; i < 3; i++) cin >> sr[i];
	cin >> cx;
	for(int i = 0; i < 3; i++) cin >> sx[i];
	int opr = int(sr[2] - 'A');
	int opx = int(sx[2] - 'A');
	if(cr == cx) {
		cout << 1;
		if(sr[0] == sx[0] && sr[1] == sx[1]) {
			cout << 1;
			if(opr < 3 && opx < 3) {
				cout << 1;
				if(abs(opr - opx) > 1) cout << 0;
				else cout << 1;
			}
			else if(opr >= 3 && opx >= 3) {
				cout << "11";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}

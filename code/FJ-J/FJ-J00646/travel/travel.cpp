#include <bits/stdc++.h>
using namespace std;
string cx, sx, cy, sy;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cx >> sx >> cy >> sy;
	int p = 1;
	if (cx == cy) cout << "1";
	else {
		cout << "0";
		p = 0;
	}
	if (p == 0) {
		cout << "000";
		return 0;
	}
	
	if (sx[0] == sy[0] && sx[1] == sy[1]) cout << "1";
	else {
		cout << "0";
		p = 0;
	}
	if (p == 0) {
		cout << "00";
		return 0;
	}
	
	if ((sx[2] >= 'A' && sx[2] <= 'C' && sy[2] >= 'A' && sy[2] <= 'C') || (sx[2] == 'D' && sy[2] == 'F') || (sx[2] == 'F' && sy[2] == 'D')) cout << "1";
	else {
		cout << "0";
		p = 0;
	}
	if (p == 0) {
		cout << "0";
		return 0;
	}
	
    if ((sx[2] == 'A' && sy[2] == 'B') || (sx[2] == 'B' && sy[2] == 'A') || (sx[2] == 'B' && sy[2] == 'C') || (sx[2] == 'C' && sy[2] == 'B') || (sx[2] == 'D' && sy[2] == 'F') || (sx[2] == 'F' && sy[2] == 'D')) {
	   	cout << "1";
    } else cout << "0";
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

bool is_h(char x, char y) {
	if (x == 'A' || x == 'B' || x == 'C') {
		if (y == 'F' || y == 'D') {
			return false;
		}
		return true;
	} else {
		if (y == 'F' || y == 'D') {
			return true;
		}
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string cr, sr;
	string cx, sx;
	
	cin >> cr >> sr >> cx >> sx;
	
	if (cr == cx) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	
	string a = sr.substr(0, 2);
	string b = sx.substr(0, 2);
	if (a == b) {
		cout << 1;
	} else {
		cout << "000"; 
		return 0;
	}
	
	char x = sr[2];
	char y = sx[2];
	if (is_h(x, y)) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	
	char tmp = x;
	x = max(tmp, y);
	y = min(y, tmp);
	
	if (x - y == 1) {
		cout << 1;
	} else {
		cout << "0";
		return 0;
	}
	cout << "\n";
	return 0;
}


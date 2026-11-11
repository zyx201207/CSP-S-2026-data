#include <bits/stdc++.h>
using namespace std;

bool jie(string& c1, string& c3) {
	if (c1 == c3) {
		return true;
	}
	return false;
}

bool pai(string& c2, string& c4) {
	if (c2[0] == c2[0] && c2[1] == c4[1]) {
		return true;
	}
	return false;
}

bool ce(string& c2, string& c4) {
	if (c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') {
		if (c4[2] == 'A' || c4[2] == 'B' || c4[2] == 'C') {
			return true;
		} else if (c4[2] == 'D' || c4[2] == 'F') {
			return false;
		}
	} else if (c2[2] == 'D' || c2[2] == 'F') {
		if (c4[2] == 'A' || c4[2] == 'B' || c4[2] == 'C') {
			return false;
		} else if (c4[2] == 'D' || c4[2] == 'F') {
			return true;
		}
	}
}

bool lin(string& c2, string& c4) {
	if (c2[2] == 'A' && c4[2] == 'B') {
		return true;
	} else if (c2[2] == 'D' && c4[2] == 'F') {
		return true;
	} else if (c4[2] == 'A' && c2[2] == 'B') {
		return true;
	} else if (c2[2] == 'F' && c4[2] == 'D') {
		return true;
	} else if (c2[2] == 'C' && c4[2] == 'B') {
		return true;
	} else if (c2[2] == 'B' && c4[2] == 'C') {
		return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if (jie(c1, c3)) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (pai(c2, c4)) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (ce(c2, c4)) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (lin(c2, c4)) {
		cout << "1";
	} else {
		cout << "0";
	}
	cout << endl;
	return 0;
}

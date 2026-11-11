#include <bits/stdc++.h>

using namespace std;

string rc, rs, xc, xs;

bool chck(const char& a, const char& b) {
	int AA, BB;
	if (a == 'A' || a == 'B' || a == 'C') {
		AA = 1;
	} else {
		AA = 0;
	}
	if (b == 'A' || b == 'B' || b == 'C') {
		BB = 1;
	} else {
		BB = 0;
	}
	
	return (AA == BB);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> rc >> rs >> xc >> xs;
	bool can_nxt = 0;
	if (rc == xc) {
		cout << 1;
		can_nxt = 1;
	} else {
		cout << 0;
	}
	
	if (can_nxt && rs[0] == xs[0] && rs[1] == xs[1]) {
		cout << 1;
		can_nxt = 1;
	} else {
		cout << 0;
		can_nxt = 0;
	}
	
	if (can_nxt && chck(rs[2], xs[2])) {
		cout << 1;
		can_nxt = 1;
	} else {
		cout << 0;
		can_nxt = 0;
	}
	
	if (can_nxt && abs((rs[2] - xs[2])) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	return 0;
}

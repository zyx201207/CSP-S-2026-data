#include<bits/stdc++.h>
using namespace std;

bool check_state(char c) {
	return c == 'A' || c == 'B' || c == 'C';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}

	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}

	if (check_state(s1[2]) == check_state(s2[2])) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}

	if (check_state(s1[2])) {
		if (abs(s1[2] - s2[2]) == 1) cout << 1;
		else cout << 0;
	} else {
		cout << 1;
	}
	
	return 0;
} 

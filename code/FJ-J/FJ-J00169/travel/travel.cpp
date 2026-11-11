#include <bits/stdc++.h>
using namespace std;
bool check_row (string &s1, string &s2) {
	int row1 = 0, row2 = 0;
	for (int i = 0; i < s1.length(); i++) {
		if ('0' <= s1[i] && s1[i] <= '9')
			row1 = row1 * 10 + s1[i] - '0';
	}
	for (int i = 0; i < s2.length(); i++) {
		if ('0' <= s2[i] && s2[i] <= '9')
			row2 = row2 * 10 + s2[i] - '0';
	}
	if (row1 == row2) {
		return true;
	}
	return false;
}
bool check_line (string &s1, string &s2) {
	char sit1 = s1[s1.length() - 1];
	char sit2 = s2[s2.length() - 1];
	if ((sit1 == 'A' || sit1 == 'B' || sit1 == 'C') && (sit2 == 'D' || sit2 == 'F')) {
		return false;
	} else if ((sit2 == 'A' || sit2 == 'B' || sit2 == 'C') && (sit1 == 'D' || sit1 == 'F')) {
		return false;
	} else {
		return true;
	}
}
bool check_sit (string &s1, string &s2) {
	char sit1 = s1[s1.length() - 1];
	char sit2 = s2[s2.length() - 1];
	if (sit2 < sit1) swap (sit2, sit1);
	if ((sit1 == 'A' && sit2 == 'B') || (sit1 == 'B' && sit2 == 'C') || (sit1 == 'D' && sit2 == 'F')) {
		return true;
	}
	return false;
}
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000" << flush;
	} else if (!check_row (s1, s2)) {
		cout << "1000" << flush;
	} else if (!check_line (s1, s2)) {
		cout << "1100" << flush;
	} else if (!check_sit (s1, s2)) {
		cout << "1110" << flush;
	} else {
		cout << "1111" << flush;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}


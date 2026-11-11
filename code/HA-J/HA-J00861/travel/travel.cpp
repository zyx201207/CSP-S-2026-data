#include<bits/stdc++.h>
using namespace std;

int c, cc;
string s, ss;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> s >> cc >> ss;
	if (c == cc) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	if (s[0] == ss[0] && s[1] == ss[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if (('A' <= s[2] && s[2] <= 'C' && 'A' <= ss[2] && ss[2] <= 'C') || ('D' <= s[2] && s[2] <= 'F' && 'D' <= ss[2] && ss[2] <= 'F')) {
		cout << "1";
	}
	else {
		cout << "00";
		return 0;
	}
	if (abs(s[2] - ss[2]) == 1 || s[2] == 'D' || s[2] == 'F') {
		cout << "1";
	}
	else {
		cout << "0";
		return 0;
	}
	return 0;
}


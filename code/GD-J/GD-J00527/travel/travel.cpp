#include<bits/stdc++.h>
using namespace std;
string a, aa, b, bb;
void check() {
	char sa = aa[2], sb = bb[2];
	if(aa[0] != bb[0] || aa[1] != bb[1]) {
		cout << "1000";
		return;
	}
	if(sa - 'D' < 0 && sb - 'D' >= 0) {
		cout << "1100";
		return;
	}
	if(sa - 'D' >= 0 && sb - 'D' < 0) {
		cout << "1100";
		return;
	}
	if((char)(sa + 1) != sb && (char)(sa - 1) != sb) {
		cout << "1110";
		return;
	}
	cout << "1111";
	return;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> aa >> b >> bb;
	if(aa[2] == 'F') aa[2] = 'E';
	if(bb[2] == 'F') bb[2] = 'E';
	if(a == b) {
		check();
	} else cout << "0000";
	return 0;
}

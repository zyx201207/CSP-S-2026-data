#include<iostream>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "0000";
	if (c1 == c2) ans[0] = '1';
	if (s1[0] == s2[0] && s1[1] == s2[1] && ans[0] == '1') ans[1] = '1';
	if (((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && ans[0] == '1' && ans[1] == '1') ans[2] = '1';
	if ((s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) && ((s1[2] != 'C' && s2[2] != 'D') && (s1[2] != 'D' && s2[2] != 'C')) && ans[0] == '1' && ans[1] == '1' && ans[2] == '1') ans[3] = '1';
	cout << ans << endl;
	return 0;
}

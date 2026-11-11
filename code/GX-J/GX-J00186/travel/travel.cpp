#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, ans = "";
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) ans += '1';
	else ans += '0';
	if (ans[0] == '1' && s1[0] == s2[0] && s1[1] == s2[1]) ans += '1';
	else ans += '0';
	if (ans[1] == '1' && s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') ans += '1';
	else if (ans[1] == '1' && s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F') ans += '1';
	else ans += '0';
	string a = "";
	a += s1[2];
	a += s2[2];
	if (ans == "111" && (a == "AB" || a == "BA" || a == "BC" || a == "CB" || a == "DF" || a == "FD")) ans += '1';
	else ans += '0';
	cout << ans << '\n';
	return 0;
}

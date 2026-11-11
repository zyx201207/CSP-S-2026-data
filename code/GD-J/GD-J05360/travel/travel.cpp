#include <bits/stdc++.h>
using namespace std;
string c_1, s_1, c_2, s_2, ans;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	string ans = "0000";
	if (c_1 == c_2) ans[0] = '1';
	string r_1 = s_1.substr(0, 2), r_2 = s_2.substr(0, 2);
	string l_1 = s_1.substr(2, 1), l_2 = s_2.substr(2, 1);
	char cl1 = l_1[0], cl2 = l_2[0];
	if (ans[0] == '1' && r_1 == r_2) ans[1] = '1';
	if (ans[1] == '1')
		if (cl1 < 'D' && cl2 < 'D' || cl1 > 'C' && cl2 > 'C') ans[2] = '1';
	if (ans[2] == '1')
		if (cl1 == cl2 + 1 || cl1 + 1 == cl2) ans[3] = '1';
	cout << ans;
	return 0;
}

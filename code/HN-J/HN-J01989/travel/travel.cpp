#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

signed main () 
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int cc1, cc2;
	if (c1[0] == '0') cc1 = c1[1] - '0';
	else cc1 = (c1[0] - '0') * 10 + c1[1] - '0';
	if (c2[0] == '0') cc2 = c2[1] - '0';
	else cc2 = (c2[0] - '0') * 10 + c2[1] - '0';
	string ans;
	if (cc1 == cc2) ans += "1";
	else ans += "0";
	
	int ss1, ss2;
	if (s1[0] == '0') ss1 = s1[1] - '0';
	else ss1 = (s1[0] - '0') * 10 + s1[1] - '0';
	if (s2[0] == '0') ss2 = s2[1] - '0';
	else ss2 = (s2[0] - '0') * 10 + s2[1] - '0';
	if (ans[0] == '1' && ss1 == ss2) ans += "1";
	else ans += "0";
	
	char s11 = s1[2], s22 = s2[2];
	
	if (ans[1] == '1' && (s11 >= 'D' && s22 >= 'D' || s11 <= 'C' && s22 <= 'C')) ans += "1";
	else ans += "0";
	
	if (ans[1] == '1' && (abs(s11 - s22) == 1 && !(s11 == 'C' && s22 == 'D' || s11 == 'D' && s22 == 'C'))) ans += "1";
	else ans += "0";
	
	cout << ans << endl;
	return 0;
}
/*



*/

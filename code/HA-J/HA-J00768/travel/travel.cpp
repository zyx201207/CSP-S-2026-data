#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1 ,s1 ,c2 ,s2;
string ans = "";

signed main()
{
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) ans += "1";
	else ans += "0";
	if (s1[0] == s2[0] && s1[1] == s2[1] && ans == "1") ans += "1";
	else ans += "0";
	int a = 0;
	int b = 0;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') a = 1;
	else if (s1[2] == 'D' || s1[2] == 'F') a = 2;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') b = 1;
	else if (s2[2] == 'D' || s2[2] == 'F') b = 2;
	if (ans == "11" && a == b) ans += "1";
	else ans += "0";
	int aa = s1[2] - '0';
	int bb = s2[2] - '0';
	if (ans == "111" && abs(aa - bb) == 1) ans += "1";
	else ans += "0";
	cout << ans << '\n';
	
	return 0;
}

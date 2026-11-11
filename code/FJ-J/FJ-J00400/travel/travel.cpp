#include <bits/stdc++.h>
//#define int long long
using namespace std;
string s;
string str1, str2, str3, str4;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> str1 >> str2 >> str3 >> str4;
	s = "";
	if(str1 == str3) s = s + "1";
	else s = s + "0";

	if(s[0] == '1' && str2[0] == str4[0] && str2[1] == str4[1]) s = s + "1";
	else s = s + "0";
	
	if(s[0] == '1' && s[1] == '1' && str2[2] <= 'C' && str4[2] <= 'C') s = s + "1";
	else if(s[0] == '1' && s[1] == '1' && 'D' <= str2[2] && 'D' <= str4[2]) s = s + "1";
	else s = s + "0";
	
	int a = str2[2] - 'A', b = str4[2] - 'A';
	if(s[0] == '1' && s[1] == '1' && s[2] == '1' && (a == b + 1 || a + 1 == b)) s = s + "1";
	else s = s + "0";

	cout << s;
	return 0;
}


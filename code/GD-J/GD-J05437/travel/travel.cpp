#include <bits/stdc++.h>
using namespace std;
int a,b;
string s,t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >> t;
	if(a != b) cout << "0000";
	else if(s[0] != t[0] || s[1] != t[1]) cout << "1000";
	else if(s[2] <= 'C' && t[2] >= 'D' || s[2] >= 'D' && t[2] <= 'C') cout << "1100";
	else if(s[2] == 'A' && t[2] == 'C' || s[2] == 'C' && t[2] == 'A') cout << "1110";
	else cout << "1111";
	return 0;
}

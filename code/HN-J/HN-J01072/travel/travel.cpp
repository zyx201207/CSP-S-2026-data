#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string ans,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	ans += char((c1 == c2) + '0');
	if (ans == "0")
	{
		cout << "0000";
		return 0;
	}
	ans += char((s1[0] == s2[0] && s2[1] == s1[1]) + '0');
	if (ans == "10")
	{
		cout << "1000";
		return 0;
	}
	if ((('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) || (('D' <= s1[2] && s1[2] <= 'F') && ('D' <= s2[2] && s2[2] <= 'F')))
	{
		ans += '1';
	}
	else
	{
		cout << "1100";
		return 0;
	}
	if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2] && !((s1[2] != 'C' && s2[2] != 'D') || (s2[2] != 'C' && s1[2] != 'D')))
	{
		ans += '1';
	}
	else
	{
		ans += '0';
	}
	cout << ans;
	return 0;
}


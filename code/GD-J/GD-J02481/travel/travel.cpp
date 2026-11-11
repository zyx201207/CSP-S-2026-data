#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("travel5.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	string ans = "0000";
	cin >> c1 >> s1 >> c2 >> s2;
	bool b = (c1 == c2);
	if (b)
	{
		ans[0] = '1';
	}
	else
	{
		cout << ans;
		return 0;
	}
	b = (s1[0] == s2[0] && s1[1] == s2[1]);
	if (b)
	{
		ans[1] = '1';
	}
	else
	{
		cout << ans;
		return 0;
	}
	b = ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'));
	if (b)
	{
		ans[2] = '1';
	}
	else
	{
		cout << ans;
		return 0;
	}
	b = (abs(s1[2] - s2[2]) == 1);
	if (b)
	{
		ans[3] = '1';
	}
	cout << ans;
	return 0;
}

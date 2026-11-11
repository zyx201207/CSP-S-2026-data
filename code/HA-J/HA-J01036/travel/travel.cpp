#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	char ans[4] = {'1', '1', '0', '0'};
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < 2; i++)
	{
		if (c1[i] != c2[i])
		{
			ans[0] = '0';
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (s1[i] != s2[i])
		{
			ans[1] = '0';
		}
	}
	int i1 = static_cast<int>(s1[2]);
	int i2 = static_cast<int>(s2[2]);
	if (((i1 >= 65) && (i1 <= 67) && (i2 >= 65) && (i2 <= 67)) || ((i1 >= 68) && (i1 <= 70) && (i2 >= 68) && (i2 <= 70)))
	{
		ans[2] = '1';
	}
	if ((i1 >= 65) && (i1 <= 67) && (i2 >= 65) && (i2 <= 67))
	{
		if ((i1 < i2 && ((i2 - i1) == 1)) || (i1 > i2 && ((i1 - i2) == 1)))
			ans[3] = '1';
	}
	else if ((i1 >= 68) && (i1 <= 70) && (i2 >= 68) && (i2 <= 70))
	{
		if ((i1 < i2 && ((i2 - i1) == 2)) || (i1 > i2 && ((i1 - i2) == 2)))
			ans[3] = '1';
	}
	for (int i = 0; i < 4; i++)
	{
		if (ans[i] == '0')
		{
			for (int j = i; j < 4; j++)
				cout << '0';
			break;
		}
		cout << ans[i]; 
	}
	return 0;
} 

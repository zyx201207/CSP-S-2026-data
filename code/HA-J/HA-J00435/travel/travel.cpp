#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s1,s2;
	cin >> n >> s1 >> m >> s2;
	if (n != m)
	{
		cout << "0000";
		return 0;
	}
	if (s1[0] != s2[0])
	{
		cout << 1000;
		return 0;
	}
	if (s1[1] != s2[1])
	{
		cout << 1000;
		return 0;
	}
	if (s1[2] > s2[2])
	{
		swap(s1,s2);
	}
	if (s1[2] != 'C' && s1[2] != 'D')
	{
		if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])
		{
			cout << 1111;
			return 0;
		}
		cout << 1110;
		return 0;
	}
	if (s1[2] == 'C')
	{
		if (s2[2] == 'B')
		{
			cout << 1111;
			return 0;
		}
		if (s2[2] == 'A')
		{
			cout << 1110;
			return 0;
		}
		cout << 1100;
		return 0;
	}
	if (s2[2] == 'E')
	{
		cout << 1111;
		return 0;
	}
	cout << 1100;
	return 0;
}

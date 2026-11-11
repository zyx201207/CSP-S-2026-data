#include <bits/stdc++.h>
using namespace std;

long long c1, c2;
char s1[3], s2[3];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1;
	for (int i = 0; i < 3; i++)
	{
		cin >> s1[i];
	}
	cin >> c2;
	for (int i = 0; i < 3; i++)
	{
		cin >> s2[i];
	}
	if (c1 != c2)
	{
		cout <<"0000";
		return 0;
	}
	else
	{
		cout <<"1";
	}

	if (s1[0] != s2[0] || s1[1] != s1[1])
	{
		cout <<"000";
		return 0;
	}
	else
	{
		cout << "1";
	}

	if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))
	{
		cout <<"00";
		return 0;
	}
	else if (s1[2] == 'F' || s1[2] == 'D')
	{
		if (s2[2] != 'F' || s2[2] != 'D')
		{
			cout << "00";
			return 0;
		}
		else
		{
			cout << "1";
		}
	}
	else if (s2[2] == 'F' || s2[2] == 'D')
	{
		if (s1[2] != 'F' || s1[2] != 'D')
		{
			cout << "00";
			return 0;
		}
		else
		{
			cout << "1";
		}
	}
	else
	{
		cout << "1";
	}
	if (abs(s1[2] - s2[2]) == 1)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}

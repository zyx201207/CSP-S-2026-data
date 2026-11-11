#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	string c1,s1,c2,s2;
	int n1=0,n2=0,n3=0;
	cin >> c1 >> c2 >> s1 >> s2;
	if (c1 == s1)
	{
		cout << 1;
		n1 = 1;
	}
	else
	{
		cout << 0;
	}
	if (n1 == 1 && (c2[0] == s2[0] && c2[1] == s2[1]))
	{
		cout << 1;
		n2 = 1;
	}
	else
	{
		cout << 0;
	}
	if (n2 == 1)
	{
		if (c2[2] == 'D' && s2[2] == 'F')
		{
			cout << 1;
		}
		if (c2[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C'))
		{
			cout <<1;
		}
		if (c2[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C'))
		{
			cout << 1;
		}
		if (c2[2] == 'C' && (s2[2] == 'A' || s2[2] == 'B'))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	if (n1 == 1 && n2 == 1 && n3 == 1)
	{
		if (c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C')
		{
			if (c2[2] == 'B')
			{
				cout << 1;
			}
			if ((c2[2] == 'A' && s2[2] == 'B') || (c2[2] == 'C' && s2[2] == 'B'))
			{
				cout << 1;
			}
		}
		if (c2[2] == 'D' || c2[2] == 'F')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}

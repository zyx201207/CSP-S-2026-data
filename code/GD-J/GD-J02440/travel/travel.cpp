#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
bool check1(char a, char b)
{
	if ((a=='D' && b=='F') || (a=='F' && b=='D'))
	{
		return 1;
	}
	else if ((a!='D' && b!='F') && (a!='F' && b!='D'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool check2(char a, char b)
{
	if (a>b)
	{
		swap(a, b);
	}
	if (a=='A' && b=='B')
	{
		return 1;
	}
	else if (a=='B' && b=='C')
	{
		return 1;
	}
	else if (a=='D' && b=='F')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1==s3)
	{
		cout << "1";
		if (s2[0]==s4[0] && s2[1]==s4[1])
		{
			cout << "1";
			if (check1(s2[2], s4[2]))
			{
				cout << "1";
				if (check2(s2[2], s4[2]))
				{
					cout << "1";
				}
				else 
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}

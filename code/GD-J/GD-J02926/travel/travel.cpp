#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << "1";
		if (s1[1] == s2[1] && s1[2] == s2[2])
		{
			cout << "1";
			if (s1[3] == "A" )
			{
				if (s2[3] == "B")
				{
					cout << "11";
				}
				else if (s2[3] == "C")
				{
					cout << "10";
				}
				else
				{
					cout << "00";
				}
			}
			else if (s1[3] == "B" )
			{
				if (s2[3] == "A" || s2[3] == "C")
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
			}
			else if (s1[3] == "C" )
			{
				if (s2[3] == "B")
				{
					cout << "11";
				}
				else if (s2[3] == "A")
				{
					cout << "10";
				}
				else
				{
					cout << "00";
				}
			}
			else if (s1[3] == "D" )
			{
				if (s2[3] == "F")
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
			}
			else
			{
				if (s2[3] == "D")
				{
					cout << "11";
				}
				else
				{
					cout << "00";
				}
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


#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3)
	{
		cout << "1";
		if(s2[1] == s4[1])
		{
			cout << "1";
			if(s4[2] - s2[2] == 1)
			{
				if(s4[2] == 'D' &&  s2[2] == 'C')
				{
					cout << "0";
				}
				else
				{
					cout << "1";
				}
			}
			else if(s4[2] == 'C' && s2[2] == 'A')
			{
				cout << "1";
			}
			else if(s2[2] == 'C' && s4[2] == 'A')
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
	if(s4[2] - s2[2] == 1)
	{
		if(s4[2] == 'D' &&  s2[2] == 'C')
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
	}
	else
	{
		cout << "0";
	}
	return 0;	
}

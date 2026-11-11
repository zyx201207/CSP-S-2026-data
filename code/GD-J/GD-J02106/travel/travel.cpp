#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[3];
	char s2[3];
	char c1[2],c2[2];
	for (int i = 0; i < 2; i++)
	{
		cin >> c1[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> s1[i];
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> c2[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> s2[i];
	}
	int ans=0;
	if(c1[1]==c2[1]&&c1[2]==c1[2])
	{
		cout << "1";
		if(s1[1]==s2[1]&&s1[2]==s1[2])
		{
			cout << "1";
			if(s1[3]<='C'&&s2[3]<='C')
			{
				cout << "1";
				if(s1[3]<='A'&&s2[3]>='C')
				{
					cout << "0";
				}
				else if(s2[3]<='A'&&s1[3]>='C')
				{
					cout << "0";
				}
				else 
				{
					cout << "1";
				}
			}
			else if(s1[3]>='D'&&s2[3]>='D')
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
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
 } 

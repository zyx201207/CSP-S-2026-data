#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2>> s2;
		if(c1 == c2)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[1] == s2[1] and s1[0] == s2[0])
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C')
	{
		if(s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C')
		{
			cout << "1";
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	else
	{
		if(s2[2] == 'D' or s2[2] == 'F')
		{
			cout << "1";
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	if(s1[2] == 'A' or s1[2] == 'C')
	{
		if(s2[2] == 'B')
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	if(s1[2] == 'B')
	{
		if(s2[2] == 'A' or s2[2] == 'C')
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	if(s1[2] == 'D')
	{
		if(s2[2] == 'F')
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	if(s1[2] == 'F')
	{
		if(s2[2] == 'D')
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	return 0;
 } 

#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int num1,num2;
char seat1,seat2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
	}
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}	
	num1 = (s1[0]-'0')*10+(s1[1]-'0');
	num2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(num1 == num2)
	{
		cout << 1;
	}
	if(num1 != num2)
	{
		cout << "000";
		return 0;
	}
	seat1 = s1[2];
	seat2 = s2[2];
	if(seat1 == 'A' || seat1 == 'B'||seat1 == 'C')
	{
		if(seat2 == 'A' || seat2 == 'B'||seat2 == 'C')
		{
			cout << 1;
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	if(seat1 == 'D' || seat1 == 'F')
	{
		if(seat2 == 'D' || seat2 == 'F')
		{
			cout << 1;
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	if(seat1 == 'A')
	{
		if(seat2 == 'B')
		{
			cout << 1;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
	if(seat1 == 'B')
	{
		if(seat2 == 'A'||seat2 == 'C')
		{
			cout << 1;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
	if(seat1 == 'C')
	{
		if(seat2 == 'B')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	if(seat1 == 'D')
	{
		if(seat2 == 'F')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	if(seat1 == 'F')
	{
		if(seat2 == 'D')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	return 0;
 } 

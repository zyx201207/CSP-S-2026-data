#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	char a1, a2, a3;
	char b1, b2, b3;
	cin >> a;
	cin >> a1 >> a2 >> a3;
	cin >> b;
	cin >> b1 >> b2 >> b3;
	if(a==b)
	{
		cout << 1;

	}
	else
	{
		cout << 0;

	}
	if(a1==b1&&a2==b2)
	{
		cout << 1;

	}
	else
	{
		cout << 0;

	}
	
	
	if(a3=='A')
	{
		if(b3=='B'||b3=='C')
		{
			cout << 1;
			if(b3=='B')
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			return 0;
		}
		else
		{
			cout << '00';
			return 0;
		}
	}
	 if(a3=='B')
	{
		if(b3=='A'||b3=='C')
		{
			cout << 11;
			
			return 0;
		}
		else
		{
			cout << '00';
			return 0;
		}
	}
	 if(a3=='C')
	{
		if(b3=='B'||b3=='A')
		{
			cout << 1;
			if(b3=='B')
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			return 0;
		}
		else
		{
			cout << '00';
			return 0;
		}
	}
	 if(a3=='D'&&b3=='F')
	{
		cout << 11;
		return 0;
	}
	
     if(a3=='F'&&b3=='D')
	{
		cout << 11;
		return 0;
	}
	else
	{
		cout << '00';
		return 0;
	}
	return 0;
}

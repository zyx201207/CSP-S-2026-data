#include <iostream>
using namespace std;
int c,ca,num;
int main()
{
	string s,sa; 
	cin >> c >> s;
	cin >> ca >> sa;
	if (c == ca)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (s[1] == sa[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (s[2] > 'C' && sa[2] > 'C')
	{
		cout << 1;
	}
	else 
	{
		if (s[2] < 'D' && sa[2] < 'D')
		{
			cout << 1;
			num = 1;
		}
		else 
		{
			cout << 0;
		}
	}
	if (num == 0)
	{
		cout << 1;
	}
	else
	{
		if(s[2] == 'A' && sa[2] == 'C')
		{
			cout << 0;
		}
		else
		{
			if(s[2] == 'C' && sa[2] == 'A')
			{
				cout << 0;
			}
			else
			{
				cout << 1;
			}
		}
	}
} 

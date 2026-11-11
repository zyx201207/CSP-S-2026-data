#include <bits/stdc++.h>
using namespace std;

int main()
{
	string c1 , s1 , c2 , s2;
	string s;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		s += '1';
		string a , b;
		for(int i = 0 ; i <= 1 ; i ++)
		{
			a += s1[i];
			b += s2[i];
		}
		if(a == b)
		{
			s += '1';
			char x , y;
			x = s1[2];
			y = s2[2];
			if(x <= 'C' && y <= 'C')
			{
				s += '1';
				if(abs(int(x) - int(y)) == 1)
				{
					s += '1';
				}
				else
				{
					s += '0';
				}
			}
			else if('D' <= x  && 'D' <= y)
			{
				s += '1';
				if(abs(int(x) - int(y)) == 1)
				{
					s += '1';
				}
				else
				{
					s += '0';
				}
			}
			else
			{
				for(int i = 1 ; i <= 2 ; i ++)
				{
					s += '0';
				}
			}
		}
		else
		{
			for(int i = 1 ; i <= 3 ; i ++)
			{
				s += '0';
			}
		}
	}
	else
	{
		for(int i = 1 ; i <= 4 ; i ++)
		{
			s += '0';
		}
	}
	cout << s;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 1;
	for (int i = 0; i < c1.length(); i++)
	{
		if (c1[i] != c2[i])
		{
			a = 0;
			break;
		}
	}
	if (a == 1)
	{
		cout << 1;
		for (int i = 0; i < 2; i++)
		{
			if (s1[i] != s2[i])
			{
				a = 0;
				break;	
			}
		} 
		if (a == 1)
		{
			cout << 1;
			if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')       
			{
			    if (s2[2] == 'E' || s2[2] == 'F')
			    {
			    	a = 0;
				}
			}
			else
			{
				if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			    {
			    	a = 0;
				}
			}  
			if (a == 1)
			{
				cout << 1; 
				if (s1[2] == 'A')
				{
					if (s2[2] == 'c')
					{
						a = 0;
					}
				} 
				else if (s1[2] == 'C')	
				{
					if (s2[2] == 'A')
					{
						a = 0;
					}
				}
				cout << a;
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

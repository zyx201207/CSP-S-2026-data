#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int a1;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		for(int i=0; i<2; i++)
		{
			if(s1[i] == s2[i])
			{
				a1++;
			}
		}
		if(a1 == 2)
		{
			cout << 1;
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
			{
				if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
				{
					cout << 1;
					if(s1[2] == 'A')
					{
						if(s2[2] == 'B')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
					else if(s1[2] == 'B')
					{
						if(s2[2] == 'A' || s2[2] == 'C')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
					else if(s1[2] == 'C')
					{
						if(s2[2] == 'B')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
				}
				else
				{
					cout << 0 << 0;
				}
			}
			else
			{
				if(s2[2] == 'D' || s2[2] == 'E')
				{
					cout << 1;
					if(s1[2] == 'D')
					{
						if(s2[2] == 'E')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
					else if(s1[2] == 'E')
					{
						if(s2[2] == 'D')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
				}
				else
				{
					cout << 0 << 0;
				}
			}
		}
		else
		{
			cout << 0 << 0 << 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;	
} 

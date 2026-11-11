#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
		int s1f = (s1[0]-'0') * 10 + s1[1]-'0',s2f = (s2[0]-'0') * 10 + s2[1]-'0';
		
		if(s1f == s2f)
		{
			cout << "1";
			char s1e = s1[2],s2e = s2[2];
			if(s1e == 'A' || s1e == 'B')
			{
				if(s2e == 'A' || s2e == 'B')
				{
					cout << "1";
					if((s1e == 'A' && s2e == 'B') || (s1e == 'B' && s2e == 'A'))
					{
						cout << "1";
					}
					else
					{
							cout << "0";
					}
				}
				else if(s2e == 'C')
				{
					cout << "1";
					if((s1e == 'A' && s2e == 'B') || (s1e == 'B' && s2e == 'A'))
					{
						cout << "1";
					}
					else
					{
						
						if((s1e == 'B' && s2e == 'C') || (s1e == 'C' && s2e == 'B'))
						{
							cout << "1";
						}
						else
						{
							cout << "0";
						}
					}
				}
				
				else
				{
					cout << "00";
				}
			}
			else if(s1e == 'C')
			{
				if(s2e == 'A' || s2e == 'B')
				{
					cout << "1";
					if((s1e == 'A' && s2e == 'B') || (s1e == 'B' && s2e == 'A'))
					{
						cout << "1";
					}
					else
					{
						
						if((s1e == 'B' && s2e == 'C') || (s1e == 'C' && s2e == 'B'))
						{
							cout << "1";
						}
						else
						{
							cout << "0";
						}
					}
				}
				else if(s2e == 'C')
				{
					cout << "1";
					if((s1e == 'A' && s2e == 'B') || (s1e == 'B' && s2e == 'A'))
					{
						cout << "1";
					}
					else
					{
						
						if((s1e == 'B' && s2e == 'C') || (s1e == 'C' && s2e == 'B'))
						{
							cout << "1";
						}
						else
						{
							cout << "0";
						}
					}
				}
				
				else
				{
					cout << "00";
				}
			}
			else
			{
				if(s2e == 'D' || s2e == 'F')
				{
					cout << "1";
					if((s1e == 'D' && s2e == 'F') || (s1e == 'F' && s2e == 'D'))
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

#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	char cs1 = c1[0];
	char cs2 = c1[1];
	char cs3 = c2[0];
	char cs4 = c2[1];
	char ss1 = s1[2];
	char ss2 = s1[2];
	if(cs1 == cs3 && cs2 == cs4)
	{
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
			{
				cout << 1;
				int cnt1 = 0;
				for(int i = 1;i <= 3; i++)
				{
					if(ss1 == 'A' + i - 1 || ss2 == 'A' + i - 1)
					{
						cnt1++;
					}
					if(cnt1 == 2){ cout << 1; break; }
						
				}
				if(cnt1 != 2)
				{
					cout << 0;
				}
				if(ss1 == 'D' && ss2 == 'F' || ss1 == 'F' && ss2 == 'D'){
					cout << 1 << 1;
					cnt1 = 2;
					return 0;
				}
				else
				{
					if(ss1 == ss2 + 1 || ss2 == ss1 + 1)
					{
						cout << 1;
						return 0;
					}
					cout << 0;
				}}
		else
		{
			cout << "00";
			if(ss1 == 'D' && ss2 == 'F' || ss1 == 'F' && ss2 == 'D')
				cout << 1;
			else
			{
				for(int i = 1; i <= 3; i++)
				{
						if(ss1 == ss2 + 1 || ss2 == ss1 + 1)
					{
						cout << 1;
						return 0;
					}
				}
				cout << 0;
			}
			return 0;
		}
	}
			else
			{
				cout << "000";
				if(ss1 == 'D' && ss2 == 'F' || ss1 == 'F' && ss2 == 'D')
					cout << 1;
				else
				{
					for(int i = 1; i <= 3; i++)
					{
						if(ss1 == ss2 + 1 || ss2 == ss1 + 1)
						{
							cout << 1;
							return 0;
						}
					}
					cout << 0;
				}
				return 0;
			}
			
			

			
	return 0;
 } 

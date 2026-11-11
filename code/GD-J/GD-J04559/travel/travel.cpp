#include <bits/stdc++.h> 
using namespace std;
string a,a1,b,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if (a==b) 
	{
		if (a1[1]==b1[1]&&a1[0]==b1[0])
		{
			if (a1[2]=='A'||a1[2]=='B'||a1[2]=='C')
			{
				if (b1[2]=='A'||b1[2]=='B'||b1[2]=='C')
				{
					if (a1[2]=='A'||a1[2]=='C')
					{
						if (b1[2]=='B')
						{
							cout<<"1111";
						}
						else
						{
							cout<<"1110";
						}
					}
					else
					{
						cout<<"1111";
					}
				}
				else 
				{
					cout<<"1100";
				}
			}
			else if (a1[2]=='D'||a1[2]=='F')
			{
				if (b1[2]=='D'||b1[2]=='F')
				{
					cout<<"1111";	
				}	
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}

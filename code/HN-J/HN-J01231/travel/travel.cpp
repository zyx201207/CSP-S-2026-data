#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int w1=0,w2=3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<1;
		if (s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<1;
			if ((s1[2]=='A' || s1[2]=='B') || s1[2]=='C')
			{
				w1=1;
			}
			else if (s1[2]=='D' || s1[2]=='F')
			{
				w1=2;
			}
			if ((s2[2]=='A' || s2[2]=='B') || s2[2]=='C')
			{
				w2=1;
			}
			else if (s2[2]=='D' || s2[2]=='F')
			{
				w2=2;
			}
			if (w1==w2)
			{
				cout<<1;
				if (w1==1)
				{
					if (s1[2]=='A' && s2[2]=='C')
					{
						cout<<0;
					}
					else if (s1[2]=='C' && s2[2]=='A')
					{
						cout<<0;
					}
					else
					{
						cout<<1;
					}
				}
				else if (w1==2)
				{
					cout<<1;
				}
			}
			else
			{
				cout<<0<<0;
			}	
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

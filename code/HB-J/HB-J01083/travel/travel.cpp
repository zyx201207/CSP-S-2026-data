#include<bits/stdc++.h>
using namespace std;
int a,b,c1,d1;
string c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
		if(c[0]==d[0]&&c[1]==d[1])
		{
			cout<<1;
			if(c[3]<='C'&&c[3]>='A')
			{
				if(d[3]<='C'&&d[3]>='A')
				{
					cout<<1;
					if(c[3]=='A'&&d[3]=='B')
					{
						cout<<1;
						return 0;
					}
					if(c[3]=='B'&&d[3]=='A')
					{
						cout<<1;
						return 0;
					}
					if(c[3]=='B'&&d[3]=='C')
					{
						cout<<1;
						return 0;
					}
					if(c[3]=='C'&&d[3]=='B')
					{
						cout<<1;
						return 0;
					}
				}
				else
				{
					cout<<0<<0;
					return 0;
				}
			}
			 if(c[3]=='F'&&d[3]=='D')
				{
						cout<<1<<1;
					return 0;
				}
					else
					{
						cout<<0<<0;
						return 0;
						}
				if(d[3]=='F'&&c[3]=='D')
				{
					cout<<1<<1;
					return 0;
					}
					else
					{
						cout<<0<<0;
						return 0;
						}
		}
		else
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
		}
	
			
	
	return 0;
	}

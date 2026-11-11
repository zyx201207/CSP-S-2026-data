#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}	
	else
	{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<1;
			if(b[2]>67&&d[2]>67)
			{
				cout<<1<<1;
				return 0;
			}
			else if(b[2]<=67&&d[2]<=67)
			{
				cout<<1;
				if(abs(b[2]-d[2])==1)
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
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
 } 

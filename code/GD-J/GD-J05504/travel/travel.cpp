#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string x,y;
	cin>>c1>>x>>c2>>y;
	if(c1==c2)
	{
		cout<<1;
		if(x[0]==y[0] && x[1]==y[1])
		{
			cout<<1;
			if(x[2]<='C' && y[2]<='C')
			{
				cout<<1;
				if(abs(x[2]-y[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(x[2]>'C' && y[2]>'C')
			{
				cout<<1<<1;
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
	return 0;
 } 

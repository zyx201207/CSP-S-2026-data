#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","f",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;	
	if(a[0]==c[0] && a[1]==c[1])
	{
		cout<<1;
		if(b[0]==d[0] &&  b[1]==d[1])
		{
			cout<<1;
			if(b[2]>='A' && b[2]<='C')
			{
				if(d[2]>='A' && d[2]<= 'C')
				{
					cout<<1;
					if(b[2]-d[2]==1 || b[2]-d[2]==-1)
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
					
				}
				else
				{
					cout<<0<<0;
				}
			}
			else if(b[2]=='D' || b[2]=='F')
			{
				if(d[2]=='D' || d[2]=='F')
				{
					cout<<1<<1;
				}
				else
				{
					cout<<0<<0;
				}
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

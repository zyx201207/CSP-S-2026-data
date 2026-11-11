#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
		if(c[0]==d[0] && c[1]==d[1])
		{
			cout<<1;
			int h=c[2],m=d[2],k='C',p=1;
			if((k-h>=0 && k-m>=0) || (k-h<0 && k-m<0))
			{
				cout<<1;
				p=1;
				if(h-m==1 || h-m==-1)
				{
					cout<<1;
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
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}

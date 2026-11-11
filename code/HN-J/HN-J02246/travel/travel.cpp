#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,x1,c2,x2;
	cin>>c1>>x1>>c2>>x2;
	if(c1==c2)
	{
		cout<<1;
		if(x1[1]==x2[1])
		{
			cout<<1;
			if((x1[2]<='C' && x2[2]<='C') || (x1[2]>'C' && x2[2]>'C'))
			{
				cout<<1;
				if(x1[2]+1==x2[2])
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

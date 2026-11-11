#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	int a=0,b=0,c=0,d=0;
	string b1,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		a=1;
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			b=1;
			if(b1[2]<'D'&&b2[2]<'D'||b1[2]>'C'&&b2[2]>'C')
			{
				c=1;
				if(b2[2]-b1[2]==1)
				{
					d=1;
				}else if(b1[2]-b2[2]==1)
				{
					d=1;
				}else
				{
					d=0;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	
	if(a==a1)
	{
		cout<<1;
		if(b[0]==b1[0]&&b[1]==b1[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		if(('a'-b[2]>=30&&'a'-b1[2]>=30)||('a'-b[2]>=28&&'a'-b1[2]>=28&&30>'a'-b[2]&&30>'a'-b1[2]))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		if(b[2]-b1[2]==1||b1[2]-b[2]==1)
		{
			if((b[2]=='C'&&b1[2]=='D')||(b1[2]=='C'&&b[2]=='D'))
			{
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
	cout<<0<<0<<0<<0;
	}
	
	return 0;
}


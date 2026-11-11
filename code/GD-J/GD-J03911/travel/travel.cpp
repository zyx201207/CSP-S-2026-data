#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
char b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0]*10+s1[1];
	a2=s2[0]*10+s2[1];
	b1=s1[2];
	b2=s2[2];
	if(c1==c2)
	{
		cout<<"1";
		if(a1==a2)
		{
			cout<<"1";
			if((b1>='A'&&b1<='C'&&b2>='A'&&b2<='C')||(b1>='D'&&b1<='F'&&b2>='D'&&b2<='F'))
			{
				cout<<"1";
			}	
			else
			{
				cout<<"0";
			}	
			if(b1>='D'&&b1<='F'&&b2>='D'&&b2<='F')
			{
				cout<<"1";
			}	
			else if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C'&&(b1+1==b2||b1==b2+1))
			{
				cout<<"1";
			}	
			else
			{
				cout<<"0";
			}	
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}

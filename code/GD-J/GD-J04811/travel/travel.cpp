#include<bits/stdc++.h>
using namespace std;
bool a=0,b=0,c=0,d=0;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
		string a1=s1.substr(0,2),a2=s2.substr(0,2);
		if(a1==a2)
		{
			b=1;
			char b1=s1[2],b2=s2[2];
			if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C')
			{
				c=1;
			}
			else if(b1>='D'&&b1<='F'&&b2>='D'&&b2<='F')
			{
				c=1;
			}
			if(b1=='A'&&b2=='B'||b1=='B'&&b2=='A')
			{
				d=1;
			}
			else if(b1=='B'&&b2=='C'||b1=='C'&&b2=='B')
			{
				d=1;
			}
			else if(b1=='D'&&b2=='E'||b1=='E'&&b2=='D')
			{
				d=1;
			}
		}
		
	}
	cout<<a<<b<<c<<d;
	return 0;
}

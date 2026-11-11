#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a,a1,b,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b)
	{
		cout<<1;
		if(a1[0]==b1[0]&&a1[1]==b1[1])
		{
			cout<<1;
			if(a1[2]>'C'&&b1[2]>'C')cout<<1<<1;
			else if(a1[2]<='C'&&b1[2]<='C')
			{
				if(a1[2]=='B'||b1[2]=='B')cout<<1<<1;
				else cout<<1<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
} 

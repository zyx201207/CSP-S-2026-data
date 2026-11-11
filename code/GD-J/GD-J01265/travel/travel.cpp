#include<bits/stdc++.h>
using namespace std;
int a,b;
string sa,sb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	if(a==b)
	{
		cout<<1;
		if(sa[0]==sb[0]&&sa[1]==sb[1])
		{
			cout<<1;
			if(sa[2]<='C'&&sb[2]<='C')
			{
				cout<<1;
				if(sa[2]=='B'||sb[2]=='B')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(sa[2]>'C'&&sb[2]>'C')
			{
				cout<<"11";
			}
			else
			{
				cout<<"00";
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

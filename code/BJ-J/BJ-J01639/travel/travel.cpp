#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	char b1=b[0];
	char b2=d[0];
	if(b1==b2&&b[1]==d[1])
	{
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	char x1=b[2];
	char x2=d[2];
	if('A'<=x1&&x1<='C'&&'A'<=x2&&x2<='C')
	{
		cout<<1;
		if(x1=='A'&&x2=='B')
		{
			cout<<1;
			return 0;
		}
		else if(x1=='B'&&x2=='A')
		{
			cout<<1;
			return 0;
		}
		else if(x1=='C'&&x2=='B')
		{
			cout<<1;
			return 0;
		}
		else if(x1=='B'&&x2=='C')
		{
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(x1=='D'&&x2=='F')
	{
		cout<<"11";
		return 0;
	}
	else if(x2=='D'&&x1=='F')
	{
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	return 0;
}

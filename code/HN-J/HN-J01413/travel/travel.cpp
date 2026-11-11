#include <bits/stdc++.h>
using namespace std;
#define gc() getchar() 
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(c>='0'&&c<='9') 
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]) 
		{
			cout<<1;
			if(((b[2]=='D'&&d[2]=='C')||(b[2]=='C'&&d[2]=='D'))) cout<<"00";
			else if(abs((b[2]-'A')-(d[2]-'A'))<=1) cout<<"11";
			else 
			{
				if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')) cout<<1;
				else cout<<0;
				cout<<0;
			}
		}
		else 
		{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}

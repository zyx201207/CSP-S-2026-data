#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<'9'&&c>'0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]&&a[0]==c[0])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1]&&b[0]==d[0])
	{
		cout<<"1";
		if(((b[2]=='C'||b[2]=='A'||b[2]=='B')&&(d[2]=='C'||d[2]=='A'||d[2]=='B'))||((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E')))
		{
			cout<<"1";
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='E'))
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
			cout<<"00";
		}
	}
	else
	{
		cout<<"000";
	}
	return 0;
}


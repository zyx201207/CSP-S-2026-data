#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int e=0,f=0;
	int jilu1=0,jilu2=0,jilu3=0,jilu4=0;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])
	{
		jilu1=1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			jilu2=1;
			if(b[2]=='C'||b[2]=='B'||b[2]=='A')e=1;
			if(d[2]=='C'||d[2]=='A'||d[2]=='B')f=1;
			if(e==f)
			{
				jilu3=1;
				if(e==0&&f==0)jilu4=1;
				else if(!((b[2]=='A'&&d[2]=='C')||(d[2]=='A'&&b[2]=='C')))jilu4=1;
			}
		}
	}
	cout<<jilu1<<jilu2<<jilu3<<jilu4;
	return 0;
}

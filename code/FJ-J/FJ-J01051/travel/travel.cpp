#include <bits/stdc++.h>
using namespace std;
int a[4],b[4],c[4];
string s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		a[0]=a[0]*10+s[i]-'0';
	}
	cin>>s;
	for (int i=0;i<s.size()-1;i++)
	{
		a[1]=a[1]*10+s[i]-'0';
	}
	a[3]=s[s.size()-1]-'A';
	if (a[3]<='C')
	{
		a[2]=1;
	}
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		b[0]=b[0]*10+s[i]-'0';
	}
	cin>>s;
	for (int i=0;i<s.size()-1;i++)
	{
		b[1]=b[1]*10+s[i]-'0';
	}
	b[3]=s[s.size()-1]-'A';
	if (b[3]<='C')
	{
		b[2]=1;
	}
	if (a[0]==b[0])
	{
		c[0]=1;
	}
	for (int i=1;i<=2;i++)
	{
		if (a[i]==b[i])
		{
			c[i]=c[i-1];
		}
	}
	if (c[2]==1&&abs(a[3]-b[3])==1)
	{
		c[3]=1;
	}
	for (int i=0;i<=3;i++)
	{
		cout<<c[i];
	}
	return 0;
}

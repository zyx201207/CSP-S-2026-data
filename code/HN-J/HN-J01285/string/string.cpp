#include <iostream>
using namespace std;
int n;
string v;
struct player
{
	long long a;
	char b;
}p[20005];
int xunhuan1()
{
	for(int i=1;i<=n/2;i++)
	{
		if(p[i].b!=p[n-i+1].b)return 0;
	}
	return 1;
}
int xunhuan2()
{
	for(int i=0;i<=v.length()/2;i++)
	{
		if(v[i]!=v[n-i+1])
		{
			v[n-i+1]=v[i];
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1||n==2)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b;
	bool o=true,l=true;
	for(int i=2;i<=n;i++)
	{
		if(p[i].a!=p[i-1].a)o=false;
		if(p[i].b!=p[i-1].b)l=false;
	}
	if(o)
	{
		int h=xunhuan1();
		if(h)
		{
			cout<<"0";
			return 0;
		}
	}
	if(l)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p[i].a;j++)
		    v+=p[i].b;
	}
	int uu=0;
	while(!xunhuan2())
	{
		uu++;
	}
	cout<<uu;
	return 0;
}

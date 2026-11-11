#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int cnt=0;
int as;
int cs;
bool pd=false;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	if(n==1)
	{
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==c[i+1])
		{
			pd=true;
			a[i+1]=a[i]+a[i+1];
			a[i]=10e9+1;
			c[i]='+';
		}
	}
	if(pd)
	{
		sort(a,a+n+1);
		sort(c,c+n+1);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==10e9+1)
		{
			as=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!='+')
		{
			cs=i;
			break;
		}
	}
	if(as==1)
	{
		cout<<'0'<<endl;
		return 0;
	}
	if(c[cs]==c[n])
	{
		if(a[as]-a[1]<0)
		{
			cout<<a[1]-a[as]<<endl;
			return 0;
		}
		else
		{
			cout<<a[as]-a[1]<<endl;
			return 0;
		}
	}
	else
		cout<<a[1]<<endl;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/

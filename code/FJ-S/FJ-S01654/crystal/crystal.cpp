#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans=1;
void q(long long x)
{
	long long b=0,js=0,x1=x;
	while(x<n)
	{
		b++;
		js+=s[x]*b;
		if(js>m)
		{
			break;
		}
		x++;
	}
	ans=max(ans,x-x1+1);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
	}
	if(n<=5005)
	{
		for(int i=1;i<=n;i++)
		{
			q(i);
		}
		cout<<ans;
	}
	else
	{
		long long b=0,js=0;
		while(b<n)
		{
			b++;
			js+=s[b+1]*b;
			if(js>m)
			{
				break;
			}
		}
		cout<<b;
	}
	return 0;
}
/*
5 5
1 2 4 8 9 
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005];
long long ans;
int f(int x)
{
	int sum=0;
	while(x)
	{
		x-=x&(-x);
		sum++;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		long long ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
			if(ans=0)
			{
				cout<<0;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int tot=0,x=n;
	for(x=n;x>=1;x--)
	{
		if(f(a[x])!=1)
		{
			ans=a[x];
			break;
		}
	}
	for(int i=x;i>=1;i--)
	{
		if(f(a[i])!=1)
		{
			ans&=a[i];
			tot++;
		}
		if(tot==m)
		{
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
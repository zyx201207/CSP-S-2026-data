#include<bits/stdc++.h>
using namespace std;
int a[200010];
int check(int a,int b)
{
	if(a==b)
	{
		return a;
	}
	int p=1,sum=0;
	while(a!=0&&b!=0)
	{
		int na=a%2,nb=b%2;
		sum+=(na*nb)*p;
		p*=2;
		a/=2;
		b/=2;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		int maxx=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,check(a[i],a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=check(sum,a[i]);
		}
		cout<<sum;
	}
	if(m==n-1)
	{
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			int ad;
			if(i==1)
			{
				ad=2;
			}
			else
			{
				ad=1;
			}
			int sum=a[ad];
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				sum=check(sum,a[j]);
			}
			if(sum>maxx) maxx=sum;
		}
		cout<<maxx;
		return 0;
	}
	
	return 0;
}
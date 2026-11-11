#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int sum=0;
	if(n>5000)
	{
		if(b[n]/(1+a[n])*2==a[n])
		{
			for(int i=1;i<=n;i++)
			{
				if(i*(i+1)/2<=m)
				{
					sum=max(sum,i);
				}
				else
				{
					continue;
				}
			}
			cout<<sum+1;
			return 0;
		}
		if(((a[1]+a[n])*((a[n]-a[1])/(a[2]-a[1])+1))/2==b[n])
		{
			int num=a[2]-a[1];
			for(int i=1;i<=n;i+=num)
			{
				if((a[i]+a[1])*((a[i]-a[1])/(a[2]-a[1])+1)<=m)
				{
					sum=max(sum,i);
				}
				else
				{
					continue;
				}
			}
			cout<<sum+1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((b[i]+m)/i>=a[i])
		{
			sum=max(sum,i);
		}
	}
	cout<<sum;
	return 0; 
} 

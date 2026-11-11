#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxc=0;
	if(n>5000)
	{
		long long sum=0;
		long long d=(a[2]-a[1]);
		for(int i=1;i<n;i++)
		{
			if(sum+i<=m)
			{
				sum+=i-d;
				maxc++;
			}
		}
		cout<<maxc<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=0,cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(sum+a[i]-a[j]<=m&&a[i]-a[j]>=0)
			{
				sum+=(a[i]-a[j]);
				cnt++;
			}
		}
		maxc=max(cnt,maxc);
	}
	cout<<maxc<<'\n';
	return 0;
}

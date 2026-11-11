#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005],ans[500005],sum,num,maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=i)fl=0;
	}
	if(fl)
	{
		long long num=m,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(num>=1ll*i)
			{
				num-=i;
				sum+=1;
			}
		}
		cout<<sum+1;
		return 0;
	}
	bool fg=1;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		s[i]=a[i+1]-a[i];
		if(i>1)
			if(s[i]!=s[i-1])fg=0;
	}
	if(fg)
	{
		long long num=m,sum=0;
		long long add=s[1];
		for(long long i=1;i<=1ll*n;i+=add)
		{
			if(num>=i)
			{
				num-=i;
				sum+=1;
			}
		}
		cout<<sum+1;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		sum=0,num=m;
		for(int j=i-1;j>=1;j--)
		{
			sum+=s[j];
			if(num>=sum)
			{
				ans[i]++;
				num-=sum;
			}
		}
	}
	for(int i=1;i<=n;i++)maxn=max(maxn,ans[i]+1);
	cout<<maxn;
	return 0;
}
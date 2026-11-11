#include <bits/stdc++.h>
using namespace std;
int a[500005];
long long n,m,ans=1;
bool oka=true,okb=true; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) oka=false;
		if(i>=3)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) okb=false;
		}
	}
	sort(a+1,a+n+1);
	if(oka)
	{
		long long sum=0;
		long long ja=1;
		while(sum+ja<=m&&ans<=n)
		{
			sum+=ja;
			ja++;
			ans++;
		}
		ans=min(ans,n);
		cout<<ans;
		return 0;
	}
	if(okb)
	{
		long long cha=a[2]-a[1],sum=0;
		long long ja=cha;
		while(sum+ja<=m&&ans<=n)
		{
			sum+=ja;
			ja+=cha;
			ans++;
		}
		cout<<min(ans,n);
		return 0;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			int tar=a[i];
			long long c[5005];
			memset(c,0x3f,sizeof(c));
			for(int j=1;j<=i;j++)
			{
				c[j]=tar-a[j];
			}
			sort(c+1,c+i+1);
			long long sum=0;
			long long k=m;
			for(int j=1;j<=i;j++)
			{
				if(c[j]>k) break;
				k-=c[j];
				sum++;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=n/2;i<=n/2;i++)
		{
			int tar=a[i];
			long long c[5005];
			memset(c,0x3f,sizeof(c));
			for(int j=1;j<=i;j++)
			{
				c[j]=tar-a[j];
			}
			sort(c+1,c+i+1);
			long long sum=0;
			long long k=m;
			for(int j=1;j<=i;j++)
			{
				if(c[j]>k) break;
				k-=c[j];
				sum++;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

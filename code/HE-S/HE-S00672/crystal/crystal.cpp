#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long num=0;
long long a[500005],c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fA=1,fB=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			fA=0;
		}
		if(i>2)
		{
			if(a[i-1]-a[i-2]!=a[i]-a[i-1])
			{
				fB=0;
			}
		}
	}
	if(fA)
	{
		for(int i=1;i<=n;i++)
		{
			if(m>=i)
			{
				num++;
				m-=i;
			}
			else
			{
				break;
			}
		}
		cout<<num+1;
		return 0;
	}
	else if(fB)
	{
		long long d=a[2]-a[1];
		for(int i=d;i<=n;i+=d)
		{
			if(m>=i)
			{
				num++;
				m-=i;
			}
			else
			{
				break;
			}
		}
		cout<<num+1;
		return 0;
	}
	else
	{
		sort(a+1,a+n+1);
		if(n<=5)
		{
			for(int jz=1;jz<=n;jz++)//a[jz]为基准数 
			{
				int r=m;
				long long sum=0;
				for(int j=jz;j>=1;j--)
				{
					if(r>=a[jz]-a[j])
					{
						sum++;
						r-=(a[jz]-a[j]);
					}
				}
				num=max(num,sum);
			}
			cout<<num;
			return 0;
		}
		else if(n<=16)
		{
			for(int jz=1;jz<=n;jz++)//a[jz]为基准数 
			{
				int r=m;
				long long sum=0;
				for(int j=jz;j>=1;j--)
				{
					if(r>=a[jz]-a[j])
					{
						sum++;
						r-=(a[jz]-a[j]);
					}
				}
				num=max(num,sum);
			}
			cout<<num;
			return 0;
		}
		else if(n<=5000)
		{
			for(int jz=1;jz<=n;jz++)//a[jz]为基准数 
			{
				int r=m;
				long long sum=0;
				for(int j=jz;j>=1;j--)
				{
					if(r>=a[jz]-a[j])
					{
						sum++;
						r-=(a[jz]-a[j]);
					}
				}
				num=max(num,sum);
			}
			cout<<num;
			return 0;
		}
		else
		{
			int r=m;
			long long sum=0;
			int jz=n/2;
			for(int j=jz;j>=1;j--)
			{
				if(r>=a[jz]-a[j])
				{
					sum++;
					r-=(a[jz]-a[j]);
				}
			}
			num=max(num,sum);
			cout<<num;
			return 0;
		}
	}
	return 0;
}

//GZ-J00483 六盘水市第四实验中学  王本贤
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long dp[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(m==1)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	
	if(m==n)
	{
		long long sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	
	
	long long sum=a[1];
	sort(a+1,a+1+n);
	for(int i=m;i>=n-m+1;i--)
	{
		sum&=a[i];
	}
	cout<<sum;
	
	
	
	
	return 0;
 } 

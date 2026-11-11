#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200002];
long long dp[202][202];
bool ok=true;
int ans=0;
bool check(long long x)
{
	int k=1;
	for(int i=1;i<=35;i++)
	{
		if(k==x+1) return true;
		if(k>x+1) return false;
		k*=2;
	}
	return false;
}
int work(long long x,long long y)
{
	int base=1;
	int sum=0;
	int kk;
	while(x > 0 && y > 0)
	{	
		int xx=x%2;
		int yy=y%2;
		if(xx==1 && yy==1) kk=1;
		else kk=0;
		sum+=kk*base;
		base*=2;
		x/=2;
		y/=2;		
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
	for(int i=1;i<=n;i++)
	{
		if(!check(a[i])) ok=false;
	}
	if(ok==true)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}else{
		if(m==1) 
		{
			sort(a+1,a+n+1);
			cout<<a[n];
			return 0;
		}
		if(m==2)
		{
			ans=0;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=i+1;j<=n;j++)
				{
					ans=max(ans,work(a[i],a[j]));
				}
			}
			cout<<ans;
			return 0;
		}
		if(m==n)
		{
			ans=a[1];
			for(int i=2;i<=n;i++)
			{
				ans=work(ans,a[i]);
			}
			cout<<ans;
			return 0;
		}
	}
}

#include<bits/stdc++.h>
using namespace std;

long long n,m,a[250000];
long long ans=-999;
void dfs(long long s,long long x,long long sum)
{
	if(x==m)
	{
		if(sum>=ans)
			ans=sum;
		return;
	}
	if(sum<ans)return;
	for(int i=s;i<=n;i++)
		dfs(i+1,x+1,sum&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	if(m==1)
	{
		long long maxn=-999;
		for(int i=1;i<=n;i++)
			maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==n)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2)
	{
		long long anst=-999;
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				
				anst=max(a[i]&a[j],anst);
			}
				
		cout<<anst;
	}
	
	else if(n<=5000)
	{
		dfs(1,0,pow(2,25)-1);
		cout<<ans;
	}
	else if(m==n-1)
	{
		long long anst=-999;
		for(int i=1;i<=n;i++)
		{
			long long sum=pow(2,25)-1;
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				else
				{
					sum=sum&a[i];
				}
			}
			anst=max(anst,sum);
		}
		cout<<anst;			
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
}

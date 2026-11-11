#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long v[200005];
long long maxd;
void dfs(long long x,long long num)
{
	if(x>m)
	{
		maxd=max(maxd,num);
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		if(v[i]==1)continue;
		v[i]=1;
		if(num==0)dfs(x+1,a[i]);
		else dfs(x+1,num&a[i]);
		v[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=20)
	{
		dfs(1,0);
		cout<<maxd;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			long long maxn=0;
			for(long long i=1;i<=n;i++)maxn=max(maxn,a[i]);
			cout<<maxn;
		}
		if(m==n)
		{
			long long total=0;
			for(long long i=1;i<=n;i++)total&=a[i];
			cout<<total;
		}
		if(m==2)
		{
			long long maxn=0;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					if(i==j)continue;
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			cout<<maxn;
		}
	}
	return 0;
}

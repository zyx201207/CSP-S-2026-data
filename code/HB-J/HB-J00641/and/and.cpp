#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum,maxa,n,m,maxn;
void dfs(long long x,long long d,long long k)
{
	if(k<maxn)return;
	if(d==m)
	{
		maxn=max(maxn,k);
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,d+1,k&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)sum=a[i];
		else sum&=a[i];
		if(a[i]>=maxa)
		{
			maxa=a[i];
		}
	}
	if(n==m)
	{
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		cout<<maxa;
		return 0;
	}
	if(m==2)
	{
		long long cmax=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cmax=max(cmax,a[i]&a[j]);
			}
		}
		cout<<cmax;
		return 0;
	}
	dfs(0,0,2147483647);
	cout<<maxn;
	return 0;
}

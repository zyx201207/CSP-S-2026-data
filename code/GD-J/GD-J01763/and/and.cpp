#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn,vis[200005],f=1;
void dfs(int k,int as)
{
	if(as==0)
	{
		return ;
	}
	if(k>m)
	{
		maxn=max(maxn,as);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(k==1)
			{
				dfs(k+1,a[i]);
			}
			else
			{
				dfs(k+1,as&a[i]);
			}
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i-1)
		{
			f=0;
		}
	}
	if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			{
				maxn=max(maxn,a[i]);
			}
		}
		else if(m==n)
		{
			maxn=a[1];
			for(int i=2;i<=n;i++)
			{
				maxn&=a[i];
			}
		}
		else
		{
			dfs(1,1);
			
		}
		cout<<maxn;
	}
	else
	{
		if(f)
		{
			sort(a+1,a+1+n);
			maxn=n-1;
			for(int i=n-1;i>n-m;i--)
			{
				maxn&=(i-1);
			}
			cout<<maxn;
		}
		else 
		{
			sort(a+1,a+1+n);
			maxn=a[n];
			for(int i=n-1;i>n-m;i++)
			{
				maxn&=a[i];
			}
			cout<<maxn;
		}
	}
	return 0;
}

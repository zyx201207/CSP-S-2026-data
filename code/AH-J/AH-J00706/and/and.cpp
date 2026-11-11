#include<bits/stdc++.h>
using namespace std;
int a[200005],f[25],n,m,maxn=INT_MIN;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int p)
{
	if(x==m)
	{
		maxn=max(maxn,p);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			if(p==0)
			{
				dfs(x+1,a[i]);
			}
			else
			{
				dfs(x+1,(p&a[i]));
			}
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(i=2;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n<=20)
	{
		dfs(0,0);
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(i=2;i<=m;i++)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
}

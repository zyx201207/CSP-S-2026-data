#include<iostream>
#include<cmath>
#define int long long
using namespace std;

int n,m;
int a[200010];
bool vis[200010];
int ma=-1;

bool check()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
			sum++;
	}
	return sum==m;
}

void dfs(int sum,int k)
{
	if(k>=m)
	{
		if(check())
			{
			for(int i=1;i<=n;i++)
		{
			cout<<vis[i]<<' '; 
		}
		cout<<sum<<'\n';
		ma=max(ma,sum);
	}

			return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=0;
			dfs(sum,k+1);
			vis[i]=1;
			dfs(sum&a[i],k+1);
		}
	}
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(a[i],1);
	}
	cout<<ma;
	return 0;
}

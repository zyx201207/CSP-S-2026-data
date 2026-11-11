#include<iostream>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[200005];
int vis[200005];
int ans;
void dfs(int x,int sum)
{
	if(x==m)
	{
		ans=max(ans,sum);	
		return;
	} 
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(x==0) dfs(x+1,a[i]);
			else dfs(x+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(a[i],maxn);
		cout<<maxn;
		return 0;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
} 

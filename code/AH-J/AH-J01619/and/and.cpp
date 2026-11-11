#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,k[40];
void dfs(int x,int y,int res)
{
	if(y==m)
	{
		ans=max(ans,res);
		return;
	}
	for(int i=x; i<=n; i++)
	{
		if(y==0) dfs(i+1,y+1,a[i]);
		else dfs(i+1,y+1,res&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	k[0]=1;
	for(int i=1; i<=20; i++) k[i]=k[i-1]*2;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(m==1)
	{
		for(int i=1; i<=n; i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2; i<=n; i++) ans&=a[i];
		cout<<ans;
	}
	else
	{
		bool f=1;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=20; j++) if(a[i]!=k[j]-1)
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			sort(a+1,a+n+1);
			cout<<a[m-n+1];
		}
		else
		{
			ans=a[n];
			for(int i=n-1; i>=n-m+1; i--) ans&=a[i];
			cout<<ans; 
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],ans,t[114514];
void dfs(int xuhao,int cishu,int cnt)
{
	if(cishu==0)
	{
		ans=max(ans,cnt);
		return;
	}
	if(cishu==m)
	{
		for(int i=1;i<=n;i++)
		{
			t[i]=1;
			dfs(i,cishu-1,a[i]);
			t[i]=0;
		}
		return;
	}
	for(int i=1;i<=n&&t[i]!=1;i++)
	{
		t[i]=1;
		dfs(i,cishu-1,(cnt&a[i]));
		t[i]=0;
	}
	return;
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
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,m,0);
	cout<<ans;
	return 0;
} 

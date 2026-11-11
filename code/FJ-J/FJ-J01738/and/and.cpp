#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,maxx=-1e9;
int a[200100];
bool vis[200100];
void dfs(int cnt,int x)
{
	if(x>m)
	{
		maxx=max(maxx,ans);
		return;
	} 
	for(int i=cnt;i<=n;i++)
		if(!vis[i])
		{
			int ans1=ans;
			if(x==1) ans=a[i];
			else ans=ans&a[i];
			vis[i]=1;
			dfs(i,x+1);
			vis[i]=0;
			ans=ans1;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	cout<<maxx;
	return 0;
}

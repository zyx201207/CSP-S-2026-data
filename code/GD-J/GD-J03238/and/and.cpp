#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],maxn=0;
int vis[100005];
long long ans=0;
//void dfs(int step,int sum)
//{
//	if(step>m)
//	{
//		return;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=1;j++)
//		vis[i]=j;
//		dfs(step+1,)
//	}
//}
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1) ans=a[i];
		if(i>1) ans=(ans&&a[i]);
		
	}
	if(m==1) cout<<maxn;
	if(m==n) cout<<ans;
//	dfs(1,0);
	return 0;
}

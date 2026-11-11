#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
bool vis[maxn]={};int a[maxn]={};
int dp[maxn]={};
int n,m;int ans=-1;
void dfs(int pos,int sum)
{
	if(pos>=m) 
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			int num=a[i] & sum;
			dfs(pos+1,num);
			vis[i]=0;
		}
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<ans<<'\n';
	return 0;
}

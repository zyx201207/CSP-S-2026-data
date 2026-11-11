#include <bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
bool vis[100005];
int n,m;
int maxn=-1e9;

void dfs(int cnt){
	if(cnt>m)
	{
		int sum=b[1];
		for(int i=2;i<=m;i++) 
		{
			sum=(sum&b[i]);
		}
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			b[cnt]=a[i];
			dfs(cnt+1);
			vis[i]=0;
		}
	}
	return ;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
	cout<<maxn;
	return 0;
}

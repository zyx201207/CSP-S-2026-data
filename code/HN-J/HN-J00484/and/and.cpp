#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxn;
int a[N];
bool vis[N];
void dfs(int x,int sum)
{
	if(x==m+1)
	{
		maxn=max(sum,maxn);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(x+1,sum&a[i]);
			vis[i]=false;
		}
	}
	return ;
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
	for(int i=1;i<=n;i++)
	{
		dfs(1,a[i]);
	}
	cout<<maxn;
	return 0;
}
/*
5 3
31 3 1 15 7
*/

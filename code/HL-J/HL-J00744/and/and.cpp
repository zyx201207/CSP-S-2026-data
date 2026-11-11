#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N],vis[N],tmp[N];
int pmax=-1;
int p;
void dfs(int depth,int start)
{
	if(depth==m+1)
	{
		for(int i=2; i<=m; i++)
		{
			p=tmp[i]&tmp[i-1];
		}
		pmax=max(p,pmax);
		return;
	}
	for(int i=start; i<=n; i++)
	{
		if(!vis[i])
		{
			tmp[depth]=a[i];
			vis[i]=1;
			dfs(depth+1,i+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	dfs(1,1);
	cout<<pmax;
	return 0;

}
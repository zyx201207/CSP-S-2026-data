#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[500005],vis[500005],ans[300005],a[500005];
void solve(int p)
{
	if(p>n) return;
	ans[a[fa[p]]]++;
	p++;
	solve(p);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	for(int i=n;i>=1;i--)
	{
		if(vis[a[i]]==0)
		{
			vis[a[i]]=i;
			fa[i]=i;
		}
		else fa[i]=vis[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		solve(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
 } 

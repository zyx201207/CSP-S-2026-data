#include<bits/stdc++.h>
const int N=5e5+10;
using namespace std;
int n,m;
int a[N],b[N],k[N],ans[N],deep[N];
vector<int> g[N];
void dfs(int x)
{	
	deep[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		dfs(g[x][i]);
		deep[x]+=deep[g[x][i]];
	}
	if(b[x]) ans[a[x]]+=deep[x];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(!k[a[i]]) 
		{
			b[i]=1;
			g[i+1].push_back(i);
		}
		else
		{
			g[k[a[i]]].push_back(i);
		}
		k[a[i]]=i;
	}
	dfs(n+1);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

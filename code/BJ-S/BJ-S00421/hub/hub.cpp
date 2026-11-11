#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector <int> a[N];
int dep[N],maxdep;
void dfs(int x,int fa)
{
	for(int y:a[x])
	{
		if(y!=fa)
		{
			dep[y]=dep[x]+1;
			maxdep=max(maxdep,dep[y]);
			dfs(y,x);
		}
	}
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			a[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		maxdep=0;
		dep[1]=0;
		dfs(1,1);
		cout<<maxdep/k<<'\n';
	}
	return 0;
}

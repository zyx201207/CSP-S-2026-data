#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,res;
int w[500005],book[500005];
struct node{
	int a,t,id;
}b[500005];
vector<int>e[1000005];
void dfs(int u,int v)
{
	book[u]=1;
	for(int i=0;i<e[u].size();i+=2)
	{
		int y=e[u][i],w=e[u][i+1];
		if(book[y]==1) continue;
		if(u==y) 
		{
			res+=w;
			return ;
		}
		dfs(y,v);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k=0,o=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(o);
			e[u].push_back(i);
			e[o].push_back(u);
			o=u;
		}
	}
	while(q--)
	{
		res=0;
		int u,v;
		cin>>u>>v;
		res+=w[u],res+=w[v];
		dfs(u,v);
		cout<<res<<endl;
	}
	return 0;
}

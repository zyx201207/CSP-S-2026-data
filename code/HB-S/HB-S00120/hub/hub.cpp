#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000005;
int c,t;
int fa[N];
int find(int x)
{
	if(x!=fa[x])
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void add(int x,int y)
{
	int xx=find(x);
	int yy=find(y);
	if(xx!=yy)
	{
		fa[yy]=xx;
	}
}
struct node
{
	int v,w;
};
vector <node> g[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(int j=1;j<=n-1;j++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back({v,1});
			g[v].push_back({u,1});
		}
		int sum=0,cnt=0;
		for(int k=1;k<=n-1;k++)
		{
			for(int l=0;l<int(g[k].size());l++)
			{
				int u=k-1;
				int v=g[k][l].v;
				int w=g[k][l].w;
				if(find(v)!=find(u))
				{
					add(u,v);
					sum+=w;
					cnt++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

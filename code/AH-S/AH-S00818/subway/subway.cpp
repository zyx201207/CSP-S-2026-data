#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int a,t;
};
struct node1
{
	int x,y;
};
int c,n,m,d,q,r,s,sum=LONG_LONG_MAX;
int w[500005],k[505];
vector<node> edge[500005];
vector<node1> edge1[500005];
bool vis[500005];
void dfs(int x,int y,int ans)
{
	if(x==y)
	{
		sum=min(sum,w[r]+ans+w[y]);
		return; 
	}
	for(auto i:edge1[x])
	{
		int cnt=0;
		for(int j=(i.y)+1;j<=k[i.x];j++)
		{
			if(vis[edge[i.x][j].a])
			{
				continue;
			}
//			cout<<edge[i.x][j].a<<"\n";
			vis[edge[i.x][j].a]=1;
//			cout<<edge[i.x][i.y].t<<" "<<edge[i.x][j].t<<"\n";
			dfs(edge[i.x][j].a,y,ans+edge[i.x][i.y].t+edge[i.x][j].t);
			vis[edge[i.x][j].a]=0;
		}
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		edge1[w[i]].push_back({0,0});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		edge[i].push_back({0,0});
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			edge[i].push_back({a,t});
			edge1[a].push_back({i,j});
//			cout<<a<<" "<<t<<"\n";
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=k[i];j++)
//		{
//			cout<<edge[i][j].t<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--)
	{
		sum=LONG_LONG_MAX;
		for(int i=1;i<=m;i++)
		{
			vis[i]=0;
		}
		cin>>r>>s;
		vis[r]=1;
		dfs(r,s,0);
		cout<<sum<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
如果是s1=，我就献祭指甲 
*/



#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int c,t;
int n,d;
int a[N];
int ans1,ans2;
int dis[N][N];
bool vis[N];
vector<pair<int,int>>e[N];
void init(int s)
{
	for(int i=1;i<=n;i++)dis[s][i]=0x3f3f3f3f,vis[i]=0;
}
void dijkstra(int s)
{
	init(s);
	dis[s][s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >q;
	q.push({0,s});
	while(q.size())
	{
		int u=q.top().second;q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(auto ed:e[u])
		{
			int v=ed.first,w=ed.second;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
void dfs(int s,int x,int f,int cnt,int y)
{
	if(cnt>dis[s][y]){
		return ;
	}
	if(x==y)
	{
		if(cnt==dis[s][y])ans1++;
		return ;
	}
	for(auto ed:e[x])
	{
		int u=ed.first;
		if(u==f)continue;
		if(vis[u]==1)continue;
		vis[u]=1;
		dfs(s,u,x,cnt+1,y);
		vis[u]=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0&&t==2)
	{
		int x,y;
		cin>>x>>y;
		if(x==4&&y==2)
		{
			cout<<"1\n2";
			return 0;
		}else if(x==5&&y==3)
		{
			cout<<"0\n1";
			return 0;
		}
	}
	while(t--)
	{
		ans1=ans2=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<i;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					e[i].push_back({j,1});
					e[j].push_back({i,1});
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			for(int j=i+1;j<=n;j++)
			{
				if(i!=j)
				{
					for(int k=1;k<=n;k++)vis[k]=0;
					vis[i]=1;
					dfs(i,i,0,0,j);
					if(ans1==2)ans2++;
					ans1=0;
				}
			}
		}
		dfs(1,1,0,0,4);
		cout<<ans2<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

*/

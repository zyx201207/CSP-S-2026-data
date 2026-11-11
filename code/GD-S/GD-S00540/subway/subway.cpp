#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int c,n,m,d,qu;
ll ww[500005];//每个地铁站到站厅的时间 
vector<pair<int,ll> >sta[500005];//每个地铁站被哪些路线经过，站厅到站台的时间
ll mina[505][505];//相互连接的路线之间最短的换乘时间
vector<pair<int,ll> >e[505];
ll ans[505][505];//每个路线的最短时间 

ll dis[505];
bool vis[505];
void di(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto ed:e[u])
		{
			int v=ed.first;ll w=ed.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v}); 
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>qu;
	//n:地铁路线数 m:地铁站数 d:每个地铁站最多被几个路线经过
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++)//地铁路线 
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{ 
			int a;ll t;cin>>a>>t;
			sta[a].push_back({i,t});
		}
	}
	memset(mina,0x3f,sizeof(mina)); 
	for(int i=1;i<=m;i++)//找直接连接的路线的最短换乘时间，枚举每个地铁站 
	{
		for(auto ea:sta[i])
		{
			for(auto eb:sta[i])//以该地铁站作为换乘点，枚举路线 
			{
				int a=ea.first;ll aw=ea.second;
				int b=eb.first;ll bw=eb.second;
				if(a==b)continue;
				if(aw+bw<mina[a][b])
				{
					mina[a][b]=aw+bw;
					mina[b][a]=aw+bw;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)//将路线当为节点，存边 
	{
		for(int j=i+1;j<=n;j++)
		{
			e[i].push_back({j,mina[i][j]});
			e[j].push_back({i,mina[i][j]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		di(i);
		for(int j=i+1;j<=n;j++)
		{
			ans[i][j]=dis[j];
			ans[j][i]=dis[j];
		}
	}
	for(int i=1;i<=qu;i++)
	{
		int s,t;
		cin>>s>>t;
		if(s==t){cout<<0<<endl;continue;}
		ll anss=LONG_LONG_MAX;
		for(auto ea:sta[s])
		{
			for(auto eb:sta[t])
			{
				int a=ea.first;ll aw=ea.second;
				int b=eb.first;ll bw=eb.second;
				anss=min(anss,ans[a][b]+aw+bw);
			}
		}
		cout<<anss+ww[s]+ww[t]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
4 2
*/

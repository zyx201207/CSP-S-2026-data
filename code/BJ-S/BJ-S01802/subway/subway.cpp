#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000000ll
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
using namespace std;	
const int Maxn=5e2+5;
const int N=5e5+5;
int c,n,m,D,q,dis[Maxn][Maxn],d[Maxn][Maxn],w[N];
int cnt[N],id[N][21],val[N][21];
vector<pii> e[Maxn];
bool vis[Maxn];
void dij(int s)
{
	priority_queue<pii> q;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) d[s][i]=inf;
	d[s][s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto p:e[u])
		{
			int v=p.first,w=p.second;
			if(d[s][v]>d[s][u]+w)
			{
				d[s][v]=d[s][u]+w;
				q.push({-d[s][v],v});
			}
		}
	}
	// cout<<"??? "<<s<<'\n';
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int p;cin>>p;
		for(int j=1;j<=p;j++)
		{
			int sta,ti;cin>>sta>>ti;
			id[sta][++cnt[sta]]=i;
			val[sta][cnt[sta]]=ti;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++) // <=9.5e7
	{
		if(cnt[i]==1) continue;
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=j+1;k<=cnt[i];k++)
			{
				int id1=id[i][j],id2=id[i][k];
				int val1=val[i][j],val2=val[i][k];
				dis[id1][id2]=min(dis[id1][id2],val1+val2);
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++) 
	// 	{
	// 		cout<<i<<" "<<j<<": "<<dis[i][j]<<'\n';
	// 	}
	// }
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dis[i][j])
			{
				e[i].push_back({j,dis[i][j]});
				e[j].push_back({i,dis[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		cout<<i<<" "<<j<<": "<<d[i][j]<<'\n';
	// 	}
	// }
	while(q--)
	{
		int u,v;cin>>u>>v;
		int ans=inf;
		for(int i=1;i<=cnt[u];i++)
		{
			for(int j=1;j<=cnt[v];j++)
			{
				int id1=id[u][i],id2=id[v][j];
				ans=min(ans,val[u][i]+val[v][j]+d[id1][id2]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
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

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35 
16
*/

// 100
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=510;
ll w[MAXN];
vector<int> a[510];
vector<ll> t[510];
int len[510];
vector<pair<int,int> > g[MAXN];
struct f{
	int id;
	ll dis;
	int tp;//0 is straight;1 is change;2 is don't know
	int lst;
	friend bool operator < (const f &x,const f &y)
	{
		return x.dis>y.dis;
	}
};
ll dis[MAXN][MAXN][2];
int vis[MAXN][MAXN];
ll tt[MAXN][MAXN];
int c,n,m,d,q;
void dijkstra(int s)
{
	priority_queue<f> pq;
	pq.push({s,0,2,0});
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[s][i][0]=0;
	while(!pq.empty())
	{
		auto u=pq.top();
		pq.pop();
		if(vis[u.id][u.lst]) continue;
		vis[u.id][u.lst]=1;
		if(u.lst!=-1) dis[u.id][u.lst][1]=dis[u.id][u.lst][0]+tt[u.id][u.lst];
		for(auto P:g[u.id])
		{
			int v=P.first,ww=P.second;
//			if(u.id==3 && v==5) cout<<"-------------------"<<dis[5][0]<<" "<<dis[5][1]<<endl;
			if(u.tp==2)
			{
				if(dis[v][ww][0]>dis[u.id][ww][0]+tt[u.id][ww])
				{
//					cout<<"v="<<v<<endl;
					dis[v][ww][0]=dis[u.id][ww][0]+tt[u.id][ww];
//					cout<<"diss="<<dis[v][0]<<" ww="<<ww<<endl;
					pq.push({v,dis[v][ww][0],0,ww}); 
				}
				if(dis[v][ww][1]>dis[u.id][ww][0]+tt[u.id][ww]+tt[v][ww])
				{
					dis[v][ww][1]=dis[u.id][ww][0]+tt[u.id][ww]+tt[v][ww];
//					cout<<"dis="<<dis[v][ww][1]<<" ww="<<ww<<endl;
					pq.push({v,dis[v][ww][1],1,ww}); 
				}
			}
			else if(ww==u.lst)
			{
				if(dis[v][ww][0]>dis[u.id][ww][0])
				{
//					cout<<"vv="<<v<<" u="<<u.id<<endl;
					dis[v][ww][0]=dis[u.id][ww][0];
					pq.push({v,dis[v][ww][0],0,u.lst});
				}
				if(dis[v][ww][1]>dis[u.id][ww][0]+tt[v][ww])
				{
//					cout<<"vvv="<<v<<endl;
					dis[v][ww][1]=dis[u.id][ww][0]+tt[v][u.lst];
//					cout<<"u="<<u.id<<" dis="<<dis[u.id][0]<<endl;
					pq.push({v,dis[v][ww][1],1,u.lst});
				}
			}
			else
			{
				if(dis[v][ww][0]>dis[u.id][u.lst][1]+tt[u.id][ww])
				{
//					cout<<"vvvv="<<v<<" ww="<<ww<<" lst="<<u.lst<<endl;
					dis[v][ww][0]=dis[u.id][u.lst][1]+tt[u.id][ww];
					pq.push({v,dis[v][ww][0],0,ww});
				}
				if(dis[v][ww][1]>dis[u.id][u.lst][1]+tt[u.id][ww]+tt[v][ww])
				{
//					cout<<"V:"<<v<<endl; 
					dis[v][ww][1]=dis[u.id][u.lst][1]+tt[u.id][ww]+tt[v][ww];
					pq.push({v,dis[v][ww][1],1,ww});
				}
			}
		}
		if(u.tp==2)
		{
			for(int i=1;i<=n;i++) dis[s][i][0]=0x3f3f3f3f;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		a[i].resize(len[i]+1);
		t[i].resize(len[i]+1);
		for(int j=1;j<=len[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			tt[a[i][j]][i]=t[i][j];
		}
		for(int j=1;j<len[i];j++)
		{
			g[a[i][j]].push_back({a[i][j+1],i});
			g[a[i][j+1]].push_back({a[i][j],i});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		ll ans=0x3f3f3f3f3f3f3f3fl;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,dis[y][i][1]+w[x]+w[y]);
//			cout<<"i="<<i<<" dis="<<dis[y][i][1]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}


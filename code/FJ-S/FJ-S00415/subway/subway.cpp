#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second 
#define mst(a,b) memset(a,b,sizeof(a))
#define endl "\n"
using namespace std;
const int N=505;
const int M=5e5+5;
const int INF=1e15;
struct Node{
	int u,v,w;
	bool operator<(const Node &p)const
	{
		return w>p.w;
	}
};
vector<Node>d{}; 
vector<int>h[N];
vector<pii>have[M];
priority_queue<Node>qq;
bool vis[N][N];
int n,m,dd,q,w[M],dis[N][N];
inline void path()
{
	for(int i=1;i<=n;++i)
	for(int j=1;j<i;++j)
	qq.push({i,j,dis[i][j]});
	while(!qq.empty())
	{
		Node u=qq.top();qq.pop();
		if(vis[u.u][u.v]) continue;
		dis[u.u][u.v]=u.w,vis[u.u][u.v]=1;
		dis[u.v][u.u]=u.w,vis[u.v][u.u]=1;
		for(auto i:h[u.u]) 
		if(dis[(d[i].u==u.u?d[i].v:d[i].u)][u.v]>u.w+d[i].w)
		{
			dis[(d[i].u==u.u?d[i].v:d[i].u)][u.v]=u.w+d[i].w;
			dis[u.v][(d[i].u==u.u?d[i].v:d[i].u)]=u.w+d[i].w;
			qq.push({min(u.v,(d[i].u==u.u?d[i].v:d[i].u)),max(u.v,(d[i].u==u.u?d[i].v:d[i].u)),u.w+d[i].w});
		}
		for(auto i:h[u.v]) 
		if(dis[(d[i].u==u.v?d[i].v:d[i].u)][u.u]>u.w+d[i].w)
		{
			dis[(d[i].u==u.v?d[i].v:d[i].u)][u.u]=u.w+d[i].w;
			dis[u.u][(d[i].u==u.v?d[i].v:d[i].u)]=u.w+d[i].w;
			qq.push({min(u.u,(d[i].u==u.v?d[i].v:d[i].u)),max(u.u,(d[i].u==u.v?d[i].v:d[i].u)),u.w+d[i].w});
		}
		d.pb(u);
		h[u.u].pb(d.size()-1);
		h[u.v].pb(d.size()-1); 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	cin>>n>>m>>dd>>q;
	for(int i=1;i<=m;++i)
	cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int x;cin>>x;
		for(int j=1;j<=x;++j)
		{
			int to,time;
			cin>>to>>time;
			have[to].pb({i,time});
		}
	}
	mst(dis,0x3f);
	for(int i=1;i<=n;++i)
	dis[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<have[i].size();++j)
		for(int k=0;k<j;++k)
		dis[have[i][j].F][have[i][k].F]=min(dis[have[i][j].F][have[i][k].F],have[i][j].S+have[i][k].S);
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	dis[i][j]=min(dis[i][j],dis[j][i]);
	path();
	while(q--)
	{
		int x,y;cin>>x>>y;
		int ans=INF;
		for(int i=0;i<have[x].size();++i)
		for(int j=0;j<have[y].size();++j)
		ans=min(ans,dis[have[x][i].F][have[y][j].F]+have[x][i].S+have[y][j].S);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

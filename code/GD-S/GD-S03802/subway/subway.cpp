#include<bits/stdc++.h>

#define rk(i,l,r) for(int i=l;i<=r;++i)
#define rp(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back 
#define pii pair<int,int>
using namespace std;
const int N =5e5+10,M=50;
//int st;
int c,n,m,d,q,k; 
int w[N];
vector<pii> vv[N][30];
vector<int> e[N][30];
int ff[N][30],tot[N],dist[N][30];//ff:tot->i mp:i->tot
bool vis[N][30];
map<int,int>mp[N];
int dp[M][30][M][30];
//int ed;
void dijkstra(int rt)
{
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[rt][0]=0;
	priority_queue<pair<int,pii> > q;
	q.push({-dist[rt][0],{rt,0}});
	//cerr<<dist[rt][0]<<" "<<rt<<" "<<0<<endl;
	while(q.size())
	{
		auto k=q.top();q.pop();
	
		int x,y;
		tie(x,y)=q.top().second;
		cerr<<dist[x][y]<<" "<<x<<" "<<ff[x][y]<<endl;
		//if(vis[x][y])continue;
		vis[x][y]=1;
		
		rk(i,0,vv[x][y].size()-1)
		{
			int z,w,l;
			tie(z,w)=vv[x][y][i];
			l=e[x][y][i];
			if(vis[z][w])continue;
			if(dist[z][w]>dist[x][y]+l)
			{
				dist[z][w]=dist[x][y]+l;
				vis[z][w]=1;
//				cerr<<dist[z][w]<<" "<<z<<" "<<ff[z][w]<<endl;
				q.push({-dist[z][w],{z,w}});
			}
		}
	}
}
void floyd()
{
	rk(k,1,m)
	rk(kk,1,20)
	{
		rk(i,1,m)
		rk(ii,1,20)
		{
			rk(j,1,m)
			{
				rk(jj,1,20)
				{
					dp[i][ii][j][jj]=min(dp[i][ii][k][kk]+dp[k][kk][j][jj],dp[i][ii][j][jj]);
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//cerr<<((&ed)-(&st))/1024/1024<<endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	if(m<=100)memset(dp,0x3f,sizeof dp);
//	if(m<=100)
//	{
//		rk(i,1,m)
//		{
//			rk(j,1,20)dp[i][j][i][j]=0;
//		}
//	}
	rk(i,1,m)cin>>w[i];
	rk(i,1,n)
	{
		cin>>k;
		int last=0;
		rk(j,1,k)
		{
			int u,v;
			cin>>u>>v;
		
			ff[u][++tot[u]]=i;
			mp[u][i]=tot[u];
			vv[u][0].push_back({u,tot[u]});
			e[u][0].push_back(v);
			vv[u][tot[u]].pb({u,0});
			e[u][tot[u]].pb(v);
			if(j>=2)
			{
				vv[last][tot[last]].pb({u,tot[u]});
				e[last][tot[last]].pb(0);
				vv[u][tot[u]].pb({last,tot[last]});
				e[u][tot[u]].pb(0);
			}
//			if(m<=100)
//			{
//				dp[u][tot[u]][u][0]=v;
//				dp[u][0][u][tot[u]]=v;
//				if(j>=2)
//				{
//					dp[last][tot[last]][u][tot[u]]=0;
//					dp[u][tot[u]][last][tot[last]]=0;
//				}
//			}
			last=u;
		}
	}
//	if(m<=100)
//	{
//		floyd();
//		rk(i,1,q)
//		{
//			int x, y;
//			cin>>x>>y;
//			
//			cout<<dp[x][0][y][0]+w[x]+w[y]<<endl;
//		}
//	}
	rk(i,1,q)
	{
		int x, y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dist[y][0]+w[x]+w[y]<<endl;
	}
	return 0;
 } 

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
int w[N];//第i条线站厅走到地铁口的路程 
int c,n,m,d,q;//m个站点,n条线路 
struct node{
	int u,w;
	bool operator <(const node &a)const{
		return w>a.w;
	};
};
priority_queue<node>pr;
bool vis[N];
int dis[N];
int st,en;
vector<int>vect;
vector<node>G[N];
int trunum;
void dijkstra()
{
	trunum=n+m;
	for(int i=1;i<=trunum;i++)
	{
		dis[i]=LLONG_MAX/2;
		vis[i]=0;
	}
	pr.push({st,0});
	dis[st]=0;
	while(!pr.empty())
	{
		node t=pr.top();pr.pop();
		if(vis[t.u])continue;
		vis[t.u]=1;
		for(auto v:G[t.u])
		{
			if(dis[v.u]>dis[t.u]+v.w)
			{
				dis[v.u]=dis[t.u]+v.w;
				pr.push({v.u,dis[v.u]});
			}
		}
	}
//	cout<<dis[en]<<endl;
	cout<<w[st]+w[en]+dis[en]<<endl;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		int cnt=0;
		while(k--)
		{
			int x,t;cin>>x>>t;
//			cout<<"YES\n";
			vect.push_back(x);
			G[i+m].push_back({x,t});
			G[x].push_back({i+m,t});//每一个站和站厅链接w的步行时间 
			if(vect.empty()!=0)
			{
				G[x].push_back({vect[cnt-1],0});//一条线中的每个站连接0 
				G[vect[cnt-1]].push_back({x,0}); 
			}
			cnt++;
		}
	}
	while(q--)
	{
		cin>>st>>en;
		dijkstra();
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3 

*/

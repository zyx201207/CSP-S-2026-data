#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e3+9;
const ll INF=4e18;
struct E
{
	int v,id;
	ll w;
};
struct Q
{
	int u,id;
	ll w;
	bool operator < (const Q& a) const
	{
		return w>a.w;
	}
};
priority_queue<Q> qp;
int c,n,m,d,q;
ll W[MAXN];
vector<E> e[MAXN][25];
ll dis[MAXN][MAXN][25];
bool f[MAXN][MAXN][25];
void dij(int s)
{
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		dis[s][i][j]=INF;
	}
	dis[s][s][0]=0;
	qp.push({s,0,0});
	while(!qp.empty())
	{
		int u=qp.top().u,ID=qp.top().id;
		qp.pop();
		if(f[s][u][ID]) continue;
		f[s][u][ID]=1;
		for(auto qwq:e[u][ID])
		{
			int v=qwq.v,id=qwq.id;
			ll w=qwq.w;
			if(dis[s][v][id]>dis[s][u][ID]+w)
			{
				dis[s][v][id]=dis[s][u][ID]+w;
				qp.push({v,id,dis[s][v][id]});
			}
		}
	}
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
    	cin>>W[i];
	}
	int u=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int id,w;
			cin>>id>>w;
			if(u!=0)
			{
				e[u][i].push_back({id,i,0});
				e[id][i].push_back({u,i,0});
			}
			e[id][0].push_back({id,i,w});
			e[id][i].push_back({id,0,w});
			u=id;
		}
		u=0;
	}
	for(int i=1;i<=m;i++)
	dij(i);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<W[x]+W[y]+dis[x][y][0]<<"\n";
	}
    return 0;
}

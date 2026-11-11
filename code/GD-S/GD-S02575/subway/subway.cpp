#include <bits/stdc++.h> 
using namespace std;
const int MAXM=1500006;
struct E
{
	int v;
	long long w;
};
struct cmp
{
	bool operator()(E x,E y) 
	{
		return x.w>y.w;
	}
};
long long c,n,m,d,q,dis[MAXM];
bool vis[MAXM];
vector<E> e[MAXM];
void add(int u,int v,long long w) 
{
	e[u].push_back({v,w});
}
void dij(int s) 
{
	for(int i=1;i<=3*m+1;i++) 
	{
		dis[i]=1e18;
		vis[i]=0;
	}
	priority_queue<E,vector<E>,cmp> q;
	q.push({s,0});dis[s]=0;
	while(!q.empty()) 
	{
		int nw=q.top().v;
		q.pop();
		if(vis[nw]) continue;
		vis[nw]=1;
		for(int i=0;i<e[nw].size();i++) 
		{
			int vv=e[nw][i].v;long long ww=e[nw][i].w;
			if(dis[vv]>dis[nw]+ww) 
			{
				dis[vv]=dis[nw]+ww;
				q.push({vv,dis[vv]});
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
		long long w;
		cin>>w;
		add(i,i+m,w);add(i+m,i,w);
	}
	for(int i=1;i<=n;i++) 
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++) 
		{
			int aa,tt;cin>>aa>>tt;
			add(m+aa,2*m+i,tt);add(2*m+i,m+aa,tt);
		}
	}
	while(q--) 
	{
		int u,v;cin>>u>>v;
		dij(u);
		cout<<dis[v]<<endl;
	}
	return 0;
}

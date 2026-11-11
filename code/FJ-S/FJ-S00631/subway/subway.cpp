#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int inf=0x3f3f3f3f;
struct edge
{
	int to,step;
	bool operator<(const edge &other)const
	{
		return other.step<step; 
	} 
};
int dis[maxn];
bool vis[maxn];
int a[1510][1510];
int c,n,m,d,q,w[maxn];
vector<edge> vec[maxn];
int dij(int beg,int lst)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i) dis[i]=inf;
	priority_queue<edge> q;
	q.push({beg,0});
	while(!q.empty())
	{
		edge e=q.top();q.pop();
		if(vis[e.to]) continue;
		vis[e.to]=1;
		dis[e.to]=e.step;
		for(vector<edge>::iterator it=vec[e.to].begin();it!=vec[e.to].end();++it)
			if(!vis[it->to]) q.push({it->to,it->step+e.step});
	}
	return dis[lst];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;++i) cin>>w[i];
	for(int t=1;t<=m;++t)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;++i)
		{
			int v,tim;
			cin>>v>>tim;
			vec[n+t].push_back({v,tim});
			vec[v].push_back({n+t,tim});
		}
	}
	for(int i=1;i<=q;++i)
	{
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<"\n";
	}
	return 0;
} 

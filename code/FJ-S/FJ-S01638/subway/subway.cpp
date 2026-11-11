#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+9;
long long inf=1e18+1;
struct node
{
	int v,z;
};
vector<node> g[maxn];
bool CMP(node a,node b)
{
	return a.z<b.z;
}
struct road{
	long long  dist;
	int s;
};
struct cmp{
	bool operator()(const road &a,const road &b){
		return a.dist>b.dist;
	}
};
ll dist[maxn],s;
ll w[maxn],c,n,m,d,qq,ans;
priority_queue< road, vector<road> , cmp > q;
void init()
{
	for(int i=1;i<=m;i++)
	dist[i]=inf;
	while(q.size()) q.pop();
	ans=0;
}
void dijkstra(int s)
{
	init();
	dist[s]=0;
	q.push({dist[s],s});
	while(!q.empty())
	{
		int dis=q.top().dist;
		int u=q.top().s;
		q.pop();
		if(dis>dist[u]) continue;
		for(auto data:g[u])	
		{
			int v=data.v;
			int w=data.z;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}	
}
int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//地铁口到站厅,站厅到下一个站厅，
	//从a站厅到b站厅的距离为该路线 dist
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
		cin>>w[i];//地铁口到站厅
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,z;
			cin>>v>>z;
			int last=0,ldis=0;
			if(j==1) last=v,ldis=z;
			else
			{
				bool ff=0;
				for(int w=0;w<g[last].size();w++)
				{
					if(g[last][w].v==v)
					g[last][w].z=min(g[last][w].z,ldis+z),ff=1;
				}
				if(ff==0) g[last].push_back({v,ldis+z});
				last=v;
				ldis=z;
			}
		}
	}	
	
	for(int i=1;i<=qq;i++){
		int l,r;
		cin>>l>>r;
		dijkstra(l);
		ans+=dist[r];
		ans+=w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}


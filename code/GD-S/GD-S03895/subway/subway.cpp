#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=5e5+5;
struct node{
	int u,w,id;
};
int c,n,m,d,qs;
int w[N];
int anss[1010][1010];
map<int,int> t[N],dis[N];
vector<pair<int,int> > g[N];
queue<node> q;
int bfs(int x,int y)
{
	for(int i=1;i<=m;i++) dis[i].clear();
	int ans=INF;
	while(!q.empty()) q.pop();
	q.push({x,0,0});
	while(!q.empty())
	{
		node mp=q.front();
		q.pop();
		if(mp.u==y)
		{
			ans=min(ans,mp.w+t[mp.u][mp.id]);
			continue;
		}
		if(mp.w>ans) continue;
//		cout<<"**"<<mp.u<<" "<<mp.w<<" "<<mp.id<<'\n';
		int u=mp.u;
		int d=mp.w;
		int id=mp.id;
		for(auto np:g[u])
		{
			int v=np.first;
			int pid=np.second;
			int w=d;
//			cout<<v<<" "<<pid<<'\n';
			if(u==v) continue;
			if(id!=pid) w+=t[u][id]+t[u][pid];
			if(dis[v].find(pid)==dis[v].end()||dis[v][pid]>w)
			{
				dis[v][pid]=w;
				q.push({v,w,pid});
			}
		}
	}
	return ans+w[x]+w[y];
}
void bfs2(int x)
{
	for(int i=1;i<=m;i++) dis[i].clear();
	while(!q.empty()) q.pop();
	q.push({x,0,0});
	anss[x][x]=0;
	while(!q.empty())
	{
		node mp=q.front();
		q.pop();
		anss[x][mp.u]=min(anss[x][mp.u],mp.w+t[mp.u][mp.id]);
		if(mp.w>anss[x][mp.u]) continue;
//		cout<<"**"<<mp.u<<" "<<mp.w<<" "<<mp.id<<'\n';
		int u=mp.u;
		int d=mp.w;
		int id=mp.id;
		for(auto np:g[u])
		{
			int v=np.first;
			int pid=np.second;
			int w=d;
//			cout<<v<<" "<<pid<<'\n';
			if(u==v) continue;
			if(id!=pid) w+=t[u][id]+t[u][pid];
			if(dis[v].find(pid)==dis[v].end()||dis[v][pid]>w)
			{
				dis[v][pid]=w;
				q.push({v,w,pid});
			}
		}
	}
	for(int i=1;i<=m;i++) anss[x][i]+=w[i]+w[x];
	anss[x][x]=0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++)
		{
			int sta,tim;
			cin>>sta>>tim;
			if(j>1)
			{
				g[lst].push_back({sta,i});
				g[sta].push_back({lst,i});
			}
			t[sta][i]=tim;
			lst=sta;
		}
	}
	if(qs<=2000) 
	{
		while(qs--)
		{
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)<<'\n';
		}
	}
	else if(m<=1000)
	{
		memset(anss,0x3f,sizeof(anss));
		for(int i=1;i<=m;i++)
		{
			bfs2(i);
		}
		while(qs--)
		{
			int x,y;
			cin>>x>>y;
			cout<<anss[x][y]<<'\n';
		}
	}
	else
	{
		while(qs--)
		{
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)<<'\n';
		}
	} 
	return 0;
}

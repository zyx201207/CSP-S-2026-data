#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,n,m,ddd,q;
int out[N];
int way[N];
int in[N];
bool vis[N];
int head[N];
int Edge_num=0,cnt=0;
int anss[N];
struct node{
	int d,id;
	bool friend operator < (node a,node b) {
		return a.d>b.d;
	} 
};
struct edge{
	int to;
	int w;
};
vector<edge> Edge[N];
priority_queue<node> que;
void add(int u,int v,int d)
{
	Edge[u].push_back({v,d});
	Edge[v].push_back({u,d});
}
void dij(int startszhi,int start)
{
	memset(vis,false,sizeof(vis));
	memset(anss,0x3f,sizeof(anss));
	node starts;
	starts.d=startszhi;
	anss[start]=0;
	starts.id=start;
	que.push(starts);
	while(!que.empty())
	{
		node hh=que.top();
		que.pop();
		if(vis[hh.id]) continue;
		vis[hh.id]=1;
		for(auto i : Edge[hh.id])
		{
			if(anss[i.to]>anss[hh.id]+i.w)
			{
				anss[i.to]=anss[hh.id]+i.w;
				node xx;
				xx.id=i.to;
				xx.d=anss[i.to];
				que.push(xx);
			}
		}
//		for(int j=head[];j>=-1;j=Edge[j].next)
//		{
//			int vv=Edge[j].to;
//			if(anss[vv]>anss[hh.id]+Edge[j].w)
//			{
//				anss[vv]=anss[hh.id]+Edge[j].w;
//				node xx;
//				xx.id=vv;
//				xx.d=anss[vv];
//				que.push(xx);
//			}
//		 } 
	} 
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>ddd>>q;
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1;i<=m;i++) cin>>out[i];
	int bianhao=m;
	for(int i=1;i<=n;i++)
	{
		cin>>way[i];
		bianhao++;
		for(int j=1;j<=way[i];j++)
		{
			int v,w;
			cin>>v>>w;
			add(bianhao,v,w);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,ed;
		cin>>st>>ed;
		dij(0,st);
		cout<<anss[ed]+out[st]+out[ed]<<endl;
	}
	return 0; 
}

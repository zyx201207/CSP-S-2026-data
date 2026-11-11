//GZ-S00305
//贵阳市白云区华师一学校
//廖博亚
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+5;
int kt[N],zl[N],st[N/5+5],ed[N/5+5];//口到站台 站台到路线/路线到站台 
int dis[10005][10005];
struct node
{
	int v,val,xl;
};
vector<node> g[N]; 
struct edge
{
	int dis,pos,cc;
	bool operator <(const edge &s)const
	{
		return dis>s.dis;
	}
};
priority_queue<edge> q;
void dijkstra(int stt)
{
	q.push({0,stt,0});
	dis[stt][stt]=0;
	while(!q.empty())
	{
		auto temp=q.top();
		q.pop();
		int d=temp.dis,x=temp.pos,ncc=temp.cc;
		if(d>dis[stt][x]) continue;
		for(auto nx:g[x])
		{
			int val=nx.val,y=nx.v,nxl=nx.xl;
			if(ncc!=nxl)
			{
				if(dis[stt][x]+val+zl[nxl]<dis[stt][y])
				{
					dis[stt][y]=dis[stt][x]+val+zl[nxl];
					q.push({dis[stt][y],y,nxl});
				}
			}
			else
			{
				if(dis[stt][x]+val<dis[stt][y])
				{
					dis[stt][y]=dis[stt][x]+val;
					q.push({dis[stt][y],y,ncc});
				}				
			}
			
		 } 
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>kt[i]; 
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			int b,cos;
			cin>>b>>cos;
			if(b==i) 
			{
				zl[i]=cos;
				continue;
			}
			g[i].push_back({b,cos,i});
			g[b].push_back({i,cos,i});
		}
	}
	for(int i=1;i<=q;i++) cin>>st[i]>>ed[i]; 
	for(int i=1;i<=q;i++)
	{
		if(dis[st[i]][ed[i]]==0x3f3f3f3f)  dijkstra(st[i]);
		cout<<dis[st[i]][ed[i]]+kt[st[i]]+kt[ed[i]]<<endl;
	} 
	return 0;
}

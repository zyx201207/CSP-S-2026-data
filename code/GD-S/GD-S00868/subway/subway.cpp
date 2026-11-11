#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=600005;
const ll inf=1e18;
ll ct,n,m,d,qu,k,x,w,a[maxn],tot=0,u,v,ans[maxn];
ll head[maxn],nxt[maxn<<1],to[maxn<<1],val[maxn<<1],cnt=0;
ll dis[maxn],vis[maxn];
struct stu
{
	ll u,dis;
};
struct stu1
{
	ll v,id;
};
vector<stu1> p[maxn];
inline bool operator < (stu a,stu b)
{
	return a.dis>b.dis;
}
priority_queue<stu> q;
inline void adde(ll u,ll v,ll w)
{
	to[++cnt]=v;
	nxt[cnt]=head[u];
	val[cnt]=w;
	head[u]=cnt;
}
inline void init(ll s)
{
	for(int i=1;i<=tot;i++) 
	{
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	q.push({s,0});
}
inline void dijkstra(ll s)
{
	init(s);
	while(!q.empty())
	{
		ll u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			ll v=to[i],w=val[i];
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
inline void fre()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>ct>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	tot=m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		tot++;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>w;
			adde(tot,x,w);
			adde(x,tot,w);
		}
	}
	for(int i=1;i<=qu;i++)
	{
		cin>>u>>v; 
		p[u].push_back({v,i});
	}
	for(int i=1;i<=m;i++)
	{
		if(p[i].empty()) continue;
		dijkstra(i);
		for(int j=0;j<p[i].size();j++)
		{
			ll v=p[i][j].v,id=p[i][j].id;
			ans[id]=a[i]+a[v]+dis[v];
		}
	}
	for(int i=1;i<=qu;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500100;
int c,n,m,d,q;
int w[N],res[1000][1000];
vector<pair<int,int> >e[N+1000];
int dis[N+1000];
bool vis[N+1000];
inline void dijk(int s)
{
	memset(dis+1,0x3f,(n+m+1)*sizeof(int));
	memset(vis+1,0,(n+m+1)*sizeof(bool));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
	dis[s]=0;
	p.push(make_pair(0,s));
	for(int i=m+1;i<s;i++)
	{
		dis[i]=res[i-m][s-m];
		vis[i]=1;
		p.push(make_pair(dis[i],i));
	}
	pair<int,int> top;
	int x,v,y,w;
	while(!p.empty())
	{
		top=p.top();
		p.pop();
		x=top.second;
		v=top.first;
		if(vis[x])
		continue;
		vis[x]=1;
		for(auto&i:e[x])//////////////////csyh
		{
			y=i.first;
			w=i.second;
			if(!vis[y]&&dis[x]+w<dis[y])
			{
				dis[y]=dis[x]+w;
				p.push(make_pair(dis[y],y));
			}
		}
	}
}
void bfs(int s)
{
	memset(dis+1,0x3f,(n+m+1)*sizeof(int));
	memset(vis+1,0,(n+m+1)*sizeof(bool));
	queue<pair<int,int>>p;
	dis[s]=0;
	p.push(make_pair(0,s));
	for(int i=m+1;i<s;i++)
	{
		dis[i]=res[i-m][s-m];
		vis[i]=1;
		p.push(make_pair(dis[i],i));
	}
	pair<int,int> top;
	int x,v,y,w;
	while(!p.empty())
	{
		top=p.front();
		p.pop();
		x=top.second;
		v=top.first;
		if(vis[x])
		continue;
		vis[x]=1;
		for(auto&i:e[x])//////////////////csyh
		{
			y=i.first;
			w=i.second;
			if(!vis[y]&&dis[x]+w<dis[y])
			{
				dis[y]=dis[x]+w;
				p.push(make_pair(dis[y],y));
			}
		}
	}
}
int init()
{
	for(int i=m+1;i<=m+n;i++)
	{
		if(12<=c&&c<=19)
		bfs(i);
		else
		dijk(i);
		for(int j=m+1;j<=m+n;j++)
		{
			res[i-m][j-m]=dis[j];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1,ki;i<=n;i++)//i+m mmmmmmmmmmmmmmmmmmmmmmm!!!
	{
		cin>>ki;
		for(int j=1,aij,tij;j<=ki;j++)
		{
			cin>>aij>>tij;
			e[i+m].push_back(make_pair(aij,tij));
			e[aij].push_back(make_pair(i+m,tij));
		}
	}
	init();
	int x,y,ans,ux,vx,uy,vy;
	while(q--)
	{
		cin>>x>>y;
		ans=LLONG_MAX;
		for(auto&i:e[x])
		{
			ux=i.first;
			vx=i.second;
			for(auto&j:e[y])
			{
				uy=j.first;
				vy=j.second;
				ans=min(ans,res[ux-m][uy-m]+vx+vy);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

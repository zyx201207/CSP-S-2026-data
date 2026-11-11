#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int c,n,m,d,q,tot;
const int MAXN=2e6+10;
ll ver[MAXN],nex[MAXN],head[MAXN],edg[MAXN];
ll t[MAXN];
int tott;
void add(int x,int y,int z)
{
	ver[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
	edg[tot]=z;
}
ll dis[MAXN];
bool vis[MAXN];
ll ans[3005][3005];
inline void dijkstra(int s)
{
	for(int i=1;i<=m*2+n+1;i++)
	{
		dis[i]=1e18;
		vis[i]=0;
	}
	priority_queue<pair<ll,int> >q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nex[i])
		{
			int y=ver[i];
			ll z=edg[i];
			if(dis[y]>dis[u]+z)
			{
				dis[y]=dis[u]+z;
				q.push({-dis[y],y});
			}
		}
	}
}
void dfs(int x,int fa)
{
	cout<<x<<" "<<fa<<endl;
	for(int i=head[x];i;i=nex[i])
	{
		int y=ver[i];
		if(y==fa)continue;
		dfs(y,x);
	}
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
		add(i,i+m,t[i]);
		add(i+m,i,t[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int len,las=0;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			ll x,val;
			cin>>x>>val;
			add(i+m*2,x+m,val);
			add(x+m,i+m*2,val);
		}
	}
	int las=0;
	if(m<=3000)
	{
		for(int i=1;i<=m;i++)
		{
			dijkstra(i);
			for(int j=1;j<=m;j++)
			{
				ans[i][j]=dis[j];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		if(m<=1000)
		{
			cout<<ans[l][r]<<'\n';
			continue;
		}
		if(las!=l)dijkstra(l);
		cout<<dis[r]<<'\n';
		las=l;
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
#define bug cout<<"_________\n";
using namespace std;
const int N=5e2+10,M=5e5+10;
const ll Sayaka=0x7fffffffffff;

int c,n,m,d,q;
ll w[M],k[N];

struct Edge
{
	int v,w;
};

vector<Edge> g[N+M];

int st,ed;
bool vis[N+M];
ll dis[N+M];

void dij()
{
	for(int i=1;i<=n+m;i++) dis[i]=Sayaka;
	dis[st]=0;
	
	while(dis[ed]==Sayaka)
	{
		int u=0;
		ll maxn=Sayaka;
		for(int i=1;i<=n+m;i++)
		{
			if(!vis[i]&&dis[i]<=maxn)
			{
				maxn=dis[i];
				u=i;
			}
		}
		
		if(u==0) return ;
		
		vis[u]=1;
		for(Edge e:g[u])
		{
			int v=e.v,w=e.w;
			dis[v]=min(dis[v],dis[u]+w);
		}
	}
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int d,t;
			cin>>d>>t;
			
			Edge u,v;
			u.v=n+i,u.w=t;
			v.v=d,v.w=t;
			g[d].push_back(u);
			g[n+i].push_back(v);
		}
	}
	
	while(q--)
	{
		cin>>st>>ed;
		dij();
		cout<<dis[ed]+w[st]+w[ed]<<"\n";
	}
}

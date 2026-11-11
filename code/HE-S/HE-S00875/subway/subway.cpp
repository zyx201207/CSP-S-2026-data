#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e12;
ll w[500005];
int t[500005][505];
vector<int> to[500005];
bool vis[500505];
ll dis[500505];
int c,n,m,d,q;
ll dij(int S,int T)
{
	for(int i=1;i<=n+m;i++) vis[i]=0,dis[i]=inf;
	priority_queue<pair<ll,int>> q;
	q.push({0,S});dis[S]=0;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:to[u])
		{
			int a=u,b=v;
			if(a>b) swap(a,b);
			if(dis[v]>dis[u]+t[a][b-m])
			{
				dis[v]=dis[u]+t[a][b-m];
				if(v==T) return dis[v];
				if(!vis[v]) q.push({-dis[v],v});
			}
		}
	}
}
int rd()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9')  c=getchar();
	while(c<='9'&&c>='0')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x;
}
char C[50];
void write(ll x)
{
	int cnt=0;
	do{
		C[++cnt]=x%10;
		x/=10;
	}while(x);
	for(int i=cnt;i>0;i--) putchar(C[i]+'0');
	putchar('\n');
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	for(int i=1;i<=n;i++)
	{
		int k;k=rd();
		for(int j=1;j<=k;j++)
		{
			int x,tim;x=rd();tim=rd();
			to[x].push_back(i+m);
			to[i+m].push_back(x);
			t[x][i]=tim;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;cin>>u>>v;
		write(w[u]+w[v]+dij(u,v));
	}
}

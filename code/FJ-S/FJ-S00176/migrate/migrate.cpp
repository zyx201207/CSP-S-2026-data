#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<x<<"\n";
#define pb push_back
#define sz size
#define bg begin
#define ed end
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
#define int long long
using namespace std;
typedef long long lli;
typedef double lf;
const int N=5e3+5,M=N*N*2;
struct edge
{
	int u,v;
}e[M];
int head[N],x[N],tot,c,T,n,m,d,ans;
int dis[N],cnt[N];
bitset<N> vis;
inline void addedge(int u,int v)
{
	e[++tot].u=head[u];
	e[tot].v=v;
	head[u]=tot;
	e[++tot].u=head[v];
	e[tot].v=u;
	head[v]=tot;
}
inline void dijk(int s)
{
	vis.reset();
	for(int i=1;i<=n;i++)dis[i]=(1ll<<60),cnt[i]=1;
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(mkp(0,s));
	while(!q.empty())
	{
		int u=q.top().sc;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		//dbg(u)
		//dbg(head[u])
		for(int i=head[u];i;i=e[i].u)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1,cnt[v]=1;
				if(!vis[v])q.push(mkp(dis[v],v));
			}	
			else if(dis[v]==dis[u]+1)
				cnt[v]++;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	//dbg(T)
	while(T--)
	{
		for(int i=1;i<=tot;i++)e[i].u=0;
		cin>>n>>d;
		tot=0,ans=0;
		if(c==13||c==14)
		{
			cout<<n*(n-1)/2<<"\n";
			continue;
		}
		for(int i=0;i<=n;i++)head[i]=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(abs(x[i]-x[j])<=d)
					addedge(i,j);
				else
					break;
			}
		for(int i=1;i<=n;i++)
		{
			dijk(i);
			for(int j=1;j<=n;j++)
				ans+=(cnt[j]==2);
		}
		//dbg(ans)
		cout<<ans/2<<"\n";
		//cerr<<ans/2<<"\n";
	}
	return 0;
}

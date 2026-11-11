#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=5e5+5,INF=1e15;
ll w[N],a[N][N],k[N],t[N][N];
pair <ll,ll> aj[N][N];
struct edge
{
	ll from,to,next,ch1,ch2,bh;
}e[M];
ll cnt,head[M];
inline void add(ll bianhao,ll u,ll v,ll ch1,ll ch2)
{
	cnt++;
	e[cnt].next=head[u];
	e[cnt].from=u;
	e[cnt].ch1=ch1;
	e[cnt].ch2=ch2;
	e[cnt].bh=bianhao;
	e[cnt].to=v;
	head[u]=cnt;
}
bool vis[N][M];
int c,q,n,m,d;
/*ll loc(ll bh,ll pos)
{
	for (int i=1;i<=k[bh];i++)
	{
		if (a[bh][i]==pos) return i;
	}
	return 0;
}*/
ll dis[M];
ll bfs(ll st,ll ed)
{
	for (ll i=1;i<=m;i++)
	dis[i]=INF;
	memset(vis,0,sizeof(vis));
	queue<pair<edge,ll>> q;
	for (ll i=head[st];i;i=e[i].next)
	{
		q.push(make_pair(e[i],e[i].ch1+e[i].ch2));
		//dis[e[i].to]=e[i].ch1+e[i].ch2;
		vis[e[i].bh][e[i].to]=1;
		vis[e[i].bh][st]=1;
	}
	while (!q.empty())
	{
		edge now=q.front().first;
		ll d=q.front().second;
		q.pop();
		ll pos=now.to,bh=now.bh;
		dis[pos]=min(dis[pos],d);
	   // cout<<bh<<' '<<now.from<<' '<<pos<<' '<<min(dis[pos],d)<<endl;
		//vis[bh][pos]=1;
		for (ll i=head[pos];i;i=e[i].next)
		{
			if (e[i].to==now.from) continue;
			if (e[i].bh==bh&&vis[e[i].bh][e[i].to]==0)
			{
				q.push(make_pair(e[i],d-now.ch2+e[i].ch2));
				//dis[e[i].to]=min(dis[pos]-now.ch2+e[i].ch2,dis[e[i].to]);
				vis[e[i].bh][e[i].to]=1;
				vis[bh][pos]=1;
				vis[e[i].bh][pos]=1;
			}
			else if (e[i].bh!=bh&&vis[e[i].bh][e[i].to]==0)
			{
				q.push(make_pair(e[i],(d+e[i].ch1+e[i].ch2)));
				//dis[e[i].to]=min((dis[pos]+e[i].ch1+e[i].ch2),dis[e[i].to]);
				vis[e[i].bh][e[i].to]=1;
				vis[bh][e[i].to]=1;
				vis[e[i].bh][pos]=1;
			}
		}
	}
	return dis[ed];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			aj[i][j].first=a[i][j];
			aj[i][j].second=t[i][j];
		}
		/*for (int j=2;j<=k[i];j++)
		{
			add(i,a[i][j-1],a[i][j],t[i][j-1],t[i][j]);
			add(i,a[i][j],a[i][j-1],t[i][j],t[i][j-1]);
		}*/
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k[i];j++)
		{
			for (int l=1;l<=k[i];l++)
			{
				if (j==l)continue;
				add(i,a[i][j],a[i][l],t[i][j],t[i][l]);
				//add(i,a[i][l],a[i][j],t[i][l],t[i][j]);
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		ll st,ed;
		scanf("%lld%lld",&st,&ed);
		cout<<bfs(st,ed)+w[st]+w[ed]<<endl;
	}
	return 0;
}

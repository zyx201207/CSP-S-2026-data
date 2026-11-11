#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=300+5;
ll n,d;
ll a[N];
struct edge{
	int to,nxt;	
}e[N*N];
ll e_cnt,head[N];
void add(ll a,ll b)
{
	e_cnt++;
	e[e_cnt].to=b;
	e[e_cnt].nxt=head[a];
	head[a]=e_cnt;
}
bool vis[N];
ll dis[N];
ll cnt[N][N];
void bfs(ll st)
{
	queue<ll> q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=3e18;
	q.push(st);
	dis[st]=0;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			if(dis[u]+1==dis[v])
			{
				cnt[st][v]++;
			}
			else if(dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll c,T;
	cin>>c>>T;
	while(T--)
	{
		memset(head,0,sizeof(head));
		e_cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					add(i,j);
					add(j,i);
				}
			}
		}
		ll ans=0;
		for(int st=1;st<=n;st++)
		{
			memset(cnt,0,sizeof(cnt));
			bfs(st);
			for(int j=st+1;j<=n;j++)
			{
				if(cnt[st][j]==1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
10 3
0 3 6 7 8 9 10 13 16 19


x1<x2<···<xn
，每次飞行的距离都不超过d
求出双径岛屿对的数量

1 2 3 4


*/

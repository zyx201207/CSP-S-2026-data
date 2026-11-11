#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=505,M=1005;
ll c,n,m,d,Q;
ll k;
ll a[N][M];
ll cnt=0;
ll w[M];
ll t[N][M];
ll dis[M][M];
struct edge{
	ll nxt,to,s;
}e[M*M];
ll e_cnt,head[N];
void add(ll a,ll b,ll c)
{
	e_cnt++;
	e[e_cnt].to=b;
	e[e_cnt].nxt=head[a];
	e[e_cnt].s=c;
	head[a]=e_cnt;
}
bool vis[M];
priority_queue<pll,vector<pll>,greater<pll>> q;
void dij(ll st){
	memset(vis,0,sizeof(vis));
	q.push({0,st});
	dis[st][st]=0;
	while(!q.empty())
	{
		ll u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			if(vis[v]) continue;
			if(dis[st][u]+e[i].s<dis[st][v])
			{
				dis[st][v]=dis[st][u]+e[i].s;
				q.push({dis[st][v],v});
			} 
		}
	}
} 
int main(){
	memset(dis,0x3f,sizeof(dis));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i],dis[i][i]=0;
	for(int u=1;u<=n;u++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[u][i];
			cin>>t[u][i];
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				ll A=a[u][i],B=a[u][j];
				add(A,B,t[u][i]+t[u][j]);
				add(B,A,t[u][i]+t[u][j]);
			}
		}	
	}
	for(int i=1;i<=m;i++)
	{
		dij(i);
	}
	while(Q--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<w[a]+w[b]+dis[a][b]<<'\n';
	}
	return 0;
}
/*

n<=500
c<=25 
m<=5e5+5
d<=20
q<=1e5+5
add(a,b,t[a][i]+t[b][i])
A: 20
B:

共有m个地铁站
往返耗时相同
i(1≤i≤n)条线路经过ki个地铁站，
编号依次为ai,1,ai,2,...,ai,ki
地铁站的地铁口走到站厅需要wv 的时间。
从站厅走到第 i
条线路的站台需要ti,j 的时间，
即ai,1,ai,2,...,ai,ki 
两两不同。
联通
每个出行计划的最小总步行时间
将从第xr 个地铁站的地铁口出发，
乘坐地铁到达第yr 个地铁站的地铁口，
n<=500
c<=25 
m<=5e5+5
d<=20
q<=1e5+5

0 2 5 20 2
4 1 9 2 5
3 
1 5 
2 7 
4 6


3 
2 3 
3 4
5 7


1 3
1 2

没事不出站

add(a,b,t[a][i]+t[b][i])

 
*/

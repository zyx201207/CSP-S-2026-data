#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
#define fi first
#define se second
using namespace std;
const ll N=5e5+5,M=5e2+5;
ll c,n,m,d,q,w[N],k[M],dis[1005][1005],dis2[N],pos[1005][M];
map<ll,ll>_dis[1005][1005],_dis2[N];
vector<ll>a[M],t[M],b[N];
vector<pair<ll,pair<ll,ll>>>edge[N];
bool vis[1005][1005][505],vis2[N][505];
void dij(ll s){
	memset(dis[s],0x3f,sizeof dis[s]);
	dis[s][s]=0;
	priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > >q;
	for(auto it:edge[s])q.push({t[it.se.fi][pos[s][it.se.fi]],{s,it.se.fi}}),_dis[s][s][it.se.fi]=t[it.se.fi][pos[s][it.se.fi]];
	while(!q.empty())
	{
		ll u=q.top().se.fi,nline=q.top().se.se;
		q.pop();
		if(vis[s][u][nline])continue;
		vis[s][u][nline]=true;
		for(auto it:edge[u])
		{
			ll v=it.fi,i=it.se.fi,j=it.se.se,newdis=0;
			if(nline==i)newdis=0;
			else newdis=t[nline][pos[u][nline]]+t[i][pos[u][i]];
			if(!_dis[s][v].count(i)||_dis[s][v][i]>_dis[s][u][nline]+newdis)_dis[s][v][i]=_dis[s][u][nline]+newdis,q.push({_dis[s][v][i],{v,i}}),dis[s][v]=min(dis[s][v],_dis[s][v][i]+t[i][pos[v][i]]);
		}
	}
}
void dij2(ll s){
	memset(dis2,0x3f,sizeof dis2);
	memset(vis2,false,sizeof vis2);
	dis2[s]=0;
	for(ll i=1;i<=n;i++)_dis2[i].clear();
	priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > >q;
	for(auto it:edge[s])q.push({t[it.se.fi][pos[s][it.se.fi]],{s,it.se.fi}}),_dis2[s][it.se.fi]=t[it.se.fi][pos[s][it.se.fi]];
	while(!q.empty())
	{
		ll u=q.top().se.fi,nline=q.top().se.se;
		q.pop();
		if(vis2[u][nline])continue;
		vis2[u][nline]=true;
		for(auto it:edge[u])
		{
			ll v=it.fi,i=it.se.fi,j=it.se.se,newdis=0;
			if(nline==i)newdis=0;
			else newdis=t[nline][pos[u][nline]]+t[i][pos[u][i]];
			if(!_dis2[v].count(i)||_dis2[v][i]>_dis2[u][nline]+newdis)_dis2[v][i]=_dis2[u][nline]+newdis,q.push({_dis2[v][i],{v,i}}),dis2[v]=min(dis2[v],_dis2[v][i]+t[i][pos[v][i]]);
		}
	}
}
void solve(){
	cin>>c>>m>>n>>d>>q;
	for(ll i=1;i<=n;i++)cin>>w[i];
	for(ll i=1;i<=m;i++)
	{
		cin>>k[i];
		for(ll j=1,x,y;j<=k[i];j++)cin>>x>>y,a[i].push_back(x),t[i].push_back(y);
		for(ll j=1;j<=k[i];j++)
		{
			if(j==1)edge[a[i][j-1]].push_back({a[i][j],{i,j}});
			else if(j==k[i])edge[a[i][j-1]].push_back({a[i][j-2],{i,j-2}});
			else edge[a[i][j-1]].push_back({a[i][j],{i,j}}),edge[a[i][j-1]].push_back({a[i][j-2],{i,j-2}});
			pos[a[i][j-1]][i]=j-1;
			b[a[i][j-1]].push_back(i);
		}
	}
	if(c<=11)
	{
		for(ll i=1;i<=n;i++)dij(i);
		for(ll i=1,u,v;i<=q;i++)cin>>u>>v,cout<<dis[u][v]+w[u]+w[v]<<'\n';
		exit(0);
	}
	for(ll i=1,u,v;i<=q;i++)cin>>u>>v,dij2(u),cout<<dis2[v]+w[u]+w[v]<<'\n';
	exit(0);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	no TLE
	ll _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
#define N 505
#define M 500005
#define ll long long
using namespace std;
int n,m;
ll w[M];
int head[N*2],pre[N*N*30],net[N*N*30],t;
ll pri[N*N*30];
ll dis[N];
bool vis[N];
vector<vector<pair<int,ll> > >v(M);
void link(int x,int y,ll z)
{
	pre[++t]=head[x];
	net[t]=y,pri[t]=z;
	head[x]=t;
	return;
}
void dij(int s)
{
	priority_queue<ll,vector<pair<ll,int>>,greater<pair<ll,int> > >q;
	for(int i=1;i<=n;i++)dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=pre[i])
		{
			int y=net[i];
			if(dis[y]>dis[x]+pri[i])
			{
				dis[y]=dis[x]+pri[i];
				q.push(make_pair(dis[y],y));
			}
		}
	}
	return;
}
ll solve(int s,int e)
{
	ll ans=1e18;
	for(auto i:v[s])
	{
		ll minl=1e18;
		dij(i.first);
		for(auto j:v[e])minl=min(minl,i.second+dis[j.first]+j.second);
		ans=min(ans,minl);
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	int d,q;
	scanf("%d",&c);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			int k;
			ll p;
			scanf("%d%lld",&k,&p);
			v[k].push_back(make_pair(i,p));
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=j+1;k<v[i].size();k++)
			{
				ll z=v[i][k].second+v[i][j].second;
				link(v[i][j].first,v[i][k].first,z);
				link(v[i][k].first,v[i][j].first,z);
			}
		}
	}
	while(q--)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		printf("%lld\n",solve(s,e)+w[s]+w[e]);
	}
	return 0;
}

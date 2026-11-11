#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,Q,st,en;
ll kz[500005],dis[500005];
vector<ll> vt[500005];
map<pair<ll,ll>,ll> mp;
bool flag[505][500005],vis[500005];
ll head[500005],cnt=0;
struct edge{ll v,w,nxt;}e[5000005];
void add(ll u,ll v,ll w)
{
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
struct node
{
	ll v,w;
	bool operator <(const node &T)const{return w>T.w;}
};
ll dijkstra()
{
	ll ans=1e15;
	for(auto s:vt[st])
	{
		for(int i=1;i<=n;i++)
		{
			dis[i]=1e15;
			vis[i]=0;
		}
		priority_queue<node> q;
		q.push({s,kz[st]+mp[{st,s}]});dis[s]=kz[st]+mp[{st,s}];
		while(!q.empty())
		{
			ll u=q.top().v;q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			if(flag[u][en])
			{
				ans=min(ans,dis[u]+mp[{en,u}]+kz[en]);
				break;
			}
			for(int i=head[u];i;i=e[i].nxt)
			{
				ll v=e[i].v;
				if(dis[v]>dis[u]+e[i].w)
				{
					dis[v]=dis[u]+e[i].w;
					q.push({v,dis[v]});
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&kz[i]);
	for(int i=1;i<=n;i++)
	{
		ll k;scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			ll bh,t;
			scanf("%lld%lld",&bh,&t);
			flag[i][bh]=1;mp[{bh,i}]=t;
			vt[bh].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)vt[i].size();j++)
		{
			for(int k=j+1;k<(int)vt[i].size();k++)
			{
				ll w=mp[{i,vt[i][j]}]+mp[{i,vt[i][k]}];
				add(vt[i][j],vt[i][k],w);
				add(vt[i][k],vt[i][j],w);
			}
		}
	}
	while(Q--)
	{
		scanf("%lld%lld",&st,&en);
		printf("%lld\n",dijkstra());
	}
	return 0;
}

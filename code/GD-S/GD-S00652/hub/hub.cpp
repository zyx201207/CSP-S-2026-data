#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e3+10,INF=0x3f3f3f3f3f3f3f3f;
struct node{ll u,v;}ed[N];
priority_queue<pair<ll,ll>> q;
vector<ll> e[N],ze[N];
vector<ll> pv1,pv2;
ll h[N];
bool vis[N];
ll c,t,n,k;
void dfs1(ll u,ll fa)
{
	pv1.push_back(u);
	for(auto v:e[u]) if(v!=fa)
	{
		ze[u].push_back(v);
		ze[v].push_back(u);
		dfs1(v,u);
	}
}
void dfs2(ll u,ll fa)
{
	pv2.push_back(u);
	for(auto v:e[u]) if(v!=fa)
	{
		ze[u].push_back(v);
		ze[v].push_back(u);
		dfs2(v,u);
	}
}
void dfs3(ll u,ll fa)
{
	h[u]=1;
	for(auto v:ze[u]) if(v!=fa)
		dfs3(v,u),h[u]=max(h[u],h[v]+1);
}
void dfs4(ll u,ll fa)
{
	h[u]=1;
	for(auto v:e[u]) if(v!=fa)
		dfs4(v,u),h[u]=max(h[u],h[v]+1);
}
ll solve(ll rt1,ll rt2)
{
	for(int j=1;j<=n;j++) vis[j]=0;
	dfs3(rt1,rt1),dfs3(rt2,rt2);
	while(q.size()) q.pop();
	q.push({h[rt1],rt1}),q.push({h[rt2],rt2});
	vis[rt1]=vis[rt2]=1;
	ll kk=k;
	while(kk--)
	{
		if(q.empty()) break;
		ll u=q.top().second; q.pop();
		for(auto v:ze[u])
			if(!vis[v]) q.push({h[v],v}),vis[v]=1;
	}
	return q.size()?q.top().first:0;
}
ll solven3()
{
	ll ans=INF;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++) ze[j].clear();
		pv1.clear(),pv2.clear();
		dfs1(ed[i].u,ed[i].v);
		dfs2(ed[i].v,ed[i].u);
		for(auto rt1:pv1)
			for(auto rt2:pv2)
				ans=min(ans,solve(rt1,rt2));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) vis[j]=0;
		dfs4(i,i);
		while(q.size()) q.pop();
		q.push({h[i],i}),vis[i]=1; ll kk=k;
		while(kk--)
		{
			if(q.empty()) break;
			ll u=q.top().second; q.pop();
			for(auto v:e[u])
				if(!vis[v]) q.push({h[v],v}),vis[v]=1;
		}
		if(q.empty()) ans=0;
		else ans=min(ans,q.top().first);
	}
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k; ll u,v;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v,ed[i]={u,v};
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<solven3()<<"\n";
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/

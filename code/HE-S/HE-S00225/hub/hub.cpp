#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4005;
ll c,t,n,k,dis[N][N],sum,ans=LLONG_MAX;
bool vis[N],vis2[N],vis3[N];
void bfs(ll s,vector<ll> a[N])
{
	queue<pair<ll,ll> > q;
	memset(vis2,0,sizeof vis2);
	vis2[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.front().first;
		int t=q.front().second;
		q.pop();
		dis[s][u]=t;
		for(ll v:a[u])
			if(!vis2[v])
			{
				vis2[v]=1;
				q.push({v,t+1});
			}
	}
	return;
}
void jisuan()
{
	ll ans2=0;
	for(int i=1;i<=n;++i)
	{
		if(vis[i]) continue;
		ll d=LLONG_MAX;
		for(int j=1;j<=n;++j)
			if(vis[j]) d=min(d,dis[i][j]);
		ans2=max(ans2,d);
	}
	ans=min(ans,ans2);
	return;
}
void dfs2(ll u,vector<ll> a[N])
{
	for(ll v:a[u])
		if(vis3[v])
		{
			vis3[v]=0;
			dfs2(v,a);
		}
	return;
}
void dfs1(ll d,ll s,vector<ll> a[N])
{
	if(d>n&&s==0)
	{
		for(int i=1;i<=n;++i) vis3[i]=vis[i];
		sum=0;
		for(ll i=1;i<=n;++i)
			if(vis3[i])
				dfs2(i,a),sum++,vis[3]=0;
		if(sum==2) jisuan();
		return;
	}
	if(d>n&&s) return;
	vis[d]=1;
	dfs1(d+1,s-1,a);
	vis[d]=0;
	dfs1(d+1,s,a);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<ll> a[N];
		for(int i=1;i<n;++i)
		{
			ll u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(ll i=1;i<=n;++i) bfs(i,a);
		dfs1(1,k,a);
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5,inf=1e18;
ll n,k,f[N],dis[N];
vector<ll> g[N];
ll calc(ll u,ll v,ll mid)
{
	queue<ll> q;
	ll ret=n;
	for(ll i=1;i<=n;i++)
	{
		ll t=g[i].size();
		if(i==u||i==v) t--;
		if(t<=1) q.push(i),dis[i]=0;
		else dis[i]=-1;
	}
	while(!q.empty())
	{
		ll u=q.front();
		if(dis[u]<mid) ret--;
		q.pop();
		for(auto v:g[u]) if(dis[v]==-1)
			dis[v]=dis[u]+1,q.push(v);
	}
	if(u==0&&v==0) return max(ret,1ll);
	bool ok1=true,ok2=true;
	for(auto tv:g[u])
	{
		if(tv==v) continue;
		if(g[tv].size()>1) ok1=false;
	}
	for(auto tv:g[v])
	{
		if(tv==u) continue;
		if(g[tv].size()>1) ok2=false;
	}
	return ret+ok1+ok2;
}
void solve()
{
	cin>>n>>k;
	for(ll u,v,i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==k)
	{
		cout<<"0\n";
		return ;
	}
	ll l=0,r=n;
	while(l<=r)
	{
		ll mid=(l+r)>>1,minn=n;
		minn=min(minn,calc(0,0,mid));
		for(ll u=1;u<=n;u++) for(auto v:g[u]) minn=min(minn,calc(u,v,mid));
		if(minn<=k) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<"\n";
	for(ll i=1;i<=n;i++) g[i].clear();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll cas,T;
	cin>>cas>>T;
	while(T--) solve();
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=7e5+5;
ll t,n,m,d,q,a[N],k[N],x,y,ans,l[N*3],tot,v[N],w[N];
vector<pair<ll,ll> > g[N*3];
void dfs(ll u,ll s,ll o)
{
	if(s>=ans) return;
	if(u==o)
	{
		ans=min(ans,s);
		return;
	}
	l[u]=1;
	for(auto f:g[u])
	{
		ll v=f.first,w=f.second;
		if(l[v]==1) continue;
		dfs(v,s+w,o);	
	}
	l[u]=0;
}
int main(){ 
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>t>>n>>m>>d>>q;
	tot=m*2;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		g[i].push_back({i+m,a[i]});
		g[i+m].push_back({i,a[i]});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		tot++;
		for(int j=1;j<=k[i];j++)
		{
			cin>>v[j]>>w[j];
			g[v[j]+m].push_back({tot,w[j]});
			g[tot].push_back({v[j]+m,w[j]});
		}
	}
	while(q--)
	{
		ans=1e18;
		cin>>x>>y;
		dfs(x,0,y);
		cout<<ans<<'\n';
	}
	return 0;
} 

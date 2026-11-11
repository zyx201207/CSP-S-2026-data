#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0)
ll c,t,n,k,d[1000006],ans,cnt,cnnt,mn;
basic_string<ll>con[1000006];
bitset<12>b;
ll dfs(ll u,ll fa,ll mxd)
{
	// cout<<b[u];
	if (!b[fa]&&b[u])cnnt++;
	if (b[u])cnt++;
	ll mmn=1e18;
	if (b[u])mxd=0;
	for (ll v:con[u])
	{
		if (v==fa)continue;
		mmn=min(mmn,dfs(v,u,mxd+1));
	}
	if (b[u])mmn=0;
	mn=max(mn,min(mmn,mxd));
	return mmn+1;
}
void chk()
{
	cnt=cnnt=0;
	mn=0;
	dfs(1,0,1000000000);
	// cout<<"\n";
	if (cnt!=k||cnnt>2)return;
	// for (ll i=1;i<=n;i++)cout<<b[i];
	// 	cout<<"\n";
	ans=min(mn,ans);
}
void dfs(ll x)
{
	if (x>n)
	{
		chk();
		return;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
}
int main()
{
	faster;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		for (ll i=1;i<=n;i++)con[i].clear();
		b.reset();
		ans=1e18;
		for (ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			con[u].pb(v);
			con[v].pb(u);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
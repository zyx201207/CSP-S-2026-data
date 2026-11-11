#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
vector<ll> a[1000001];
ll d[1000001];
bool v[1000001];
queue<ll> q;
ll n,k;
void dfs(ll x,ll p)
{
	v[x]=1;
//	if (p==262||p==268||p==518||p==524)cout<<x<<' ';
	for (ll i=0;i<a[x].size();i++)
	{
		ll y=a[x][i];
		if ((p&(1<<y-1))&&v[y]==0)
		{
			dfs(y,p);
//			if (p==262||p==268||p==518||p==524)cout<<x<<"->"<<y<<'\n';
		}
	}
}
ll solve(ll x)
{
	ll xx=x,cnt=0;
	while (xx)
	{
		cnt+=xx%2; 
		xx/=2;
	}
	if (cnt!=k)return 1e18;
	cnt=0;
	for (ll i=1;i<=n;i++)v[i]=0;
	for (ll i=1;i<=n;i++)
	{
		if ((x&(1<<i-1))&&v[i]==0)
		{
			dfs(i,x);
			cnt++;
//			if (x==262||x==268||x==276||x==518||x==524||x==532)cout<<'\n';
		}
	}
//	if (x==262||x==268||x==276||x==518||x==524||x==532)cout<<'\n';
	if (cnt>2)return 1e18;
	while (q.size())q.pop();
	for (ll i=1;i<=n;i++)
	{
		if (x&(1<<i-1))
		{
			d[i]=0;
			q.push(i);
		}
		else d[i]=-1e18;
	}
	ll res=-1e18;
	while (q.size())
	{
		ll x=q.front();
		q.pop();
		for (ll i=0;i<a[x].size();i++)
		{
			ll y=a[x][i];
			if (d[y]==-1e18)
			{
				d[y]=d[x]+1;
				res=max(res,d[y]);
				q.push(y);
			}
		}
	}
//	if (x==262||x==268||x==276||x==518||x==524||x==532)
//	{
//		for (ll i=1;i<=n;i++)if (x&(1<<i-1))cout<<i<<' ';
//		cout<<'\n';
//	}
	return res;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll c,T;
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>k;
		for (ll i=1;i<=n;i++)a[i].clear();
		for (ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ll ans=1e18;
		for (ll i=1;i<(1<<n);i++)ans=min(solve(i),ans);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
Today is my third CSP-J/S(I'm in grade eight)
Before today,I didn't solve the second problem
But this time I solved it last hour
I still don't know how to solve the third or the forth problem
I'm so tired¡­¡­
My highest points:100+100+40+15=255pts(~~I want a BLUE TICK~~)
Wish me RP++
							CQ-J00525/CQ-S00475(Luogu UID:832774)
							2026/10/31 18:10
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+7;
ll Tid;
ll n,d;
ll pos[N];
ll tl[N],tr[N];
ll gol[N],gor[N];
ll cnt;
ll sl[N],sr[N];
ll f[N];
vector<ll>edge[N];
ll dis[N],g[N];
ll ans;
inline void getans(ll s)
{
	for(ll i=1;i<=n;i++)dis[i]=1e9,g[i]=0;
	queue<ll>q;
	dis[s]=0,g[s]=1;
	q.push(s);
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		for(ll v:edge[x])
		{
			if(dis[v]>dis[x]+1)
			{
				dis[v]=dis[x]+1;
				g[v]=g[x];
				q.push(v);
			}
			else if(dis[v]==dis[x]+1)
			{
				g[v]+=g[x];
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(g[i]==2)
		{
			ans++;
		}
	}
}
ll t[N],s[N];
inline void solve()
{
	ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++)
	{
		cin>>pos[i];
	}
	if(n<=5000)
	{
		for(ll i=1;i<=n;i++)edge[i].clear();
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(pos[j]-pos[i]<=d)
				{
					edge[i].push_back(j); 
				}
			}
		}
		for(ll i=1;i<=n;i++)
		{
			getans(i);
		}
		cout<<ans<<'\n';
		return;
	}
	for(ll i=1,j=1;i<=n;i++)
	{
		j=max(j,i);
		while(j<=n&&pos[j]-pos[i]<=d)j++;
		tr[i]=j-1;
		tl[i]=i+1;
	}
	for(ll i=n,j=n;i;i--)
	{
		j=min(j,i);
		sr[i]=i-1;
		while(j>=1&&pos[i]-pos[j]<=d)j--;
		sl[i]=j+1;
	}
	for(ll i=1;i<=n;i++)
	{
		s[i]=t[i]=1;
		gol[i]=gor[i]=-1;
		if(tr[i]-tl[i]+1>=2)
		{
			ll p1=tr[i];
			ll p2=tr[i]-1;
			ll L=max(tl[p1],tl[p2]);
			ll R=min(tr[p1],tr[p2]);
			if(p2-1!=i)
				L=max(L,tr[p2-1]+1);
			if(L<=R)
			{
				ans+=R-L+1;
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	ll T;cin>>Tid>>T;
	while(T--)solve();
}

/*
每个点连向一个区间

判断两个点最短路数是否为 2 

----

寻找极短的最短路为 2 方案。

只可能是长度为 2 的路径，O(n) 计算。

最多只有 2n 个 

对于一个 [l,r]

a-->l 唯一的路径数 

r-->b 唯一的路径数 

减去会跳到 l,r 中间的方案数。 

不会。。。。。 
*/ 

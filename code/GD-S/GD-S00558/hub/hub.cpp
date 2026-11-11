#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll MAXN=5e5+5;
const ll inf=LONG_LONG_MAX;
ll n,m,ans,fa[MAXN];
vector<ll>ed[MAXN];
bitset<MAXN>vis;
ll dfs2(ll x,ll y)
{
	if(vis[x])return 0;
	ll answer=1e15;
	for(auto q:ed[x])
	{
		if(q==y)continue;
		answer=min(answer,dfs2(q,x)+1);
	}
	return answer;
}
ll findfa(ll x)
{
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
void dfs(ll x,ll y)
{
	if(y>m)
	{
		ll t=0,cnt=m;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				fa[i]=i;
				for(auto q:ed[i])
				{
					if(vis[q]&&q<i)
					{
						if(findfa(q)!=i)
						{
							fa[findfa(q)]=i,cnt--;
						}
					}
				}
			}
		}
		if(cnt>2)return ;
		for(int i=1;i<=n;i++)
		{
			t=max(t,dfs2(i,0));
		}
		ans=min(ans,t);
		return ;
	}
	if(x>n)return ;
	for(int i=x;i<=n;i++)
	{
		vis[i]=1;
		dfs(i+1,y+1);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>m;
	ans=inf;
	for(int i=1;i<n;i++)
	{
		ll q,w;
		cin>>q>>w;
		ed[q].push_back(w);
		ed[w].push_back(q);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)ed[i].resize(0);
	cout<<ans<<"\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin>>T;
	cin>>T;
	while(T--)solve();
	return 0;
}

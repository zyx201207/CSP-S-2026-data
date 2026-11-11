#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define il inline
using namespace std;
const int maxn=2e6+10;
int o,n,k,cnt,ans;
int fa[maxn],d[maxn];
bool flag[maxn],vis[maxn];
vector<int> g[maxn];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool check()
{
	int num=0;
	for(int i=1;i<=n;i++) fa[i]=i,num+=flag[i];
	if(num!=k) return 0;
	for(int i=1;i<=n;i++)
		for(auto j:g[i]) if(flag[i]&&flag[j]) fa[get(i)]=get(j);
	int cnt=0;
	for(int i=1;i<=n;i++) if(flag[i]) cnt+=(get(i)==i);
	return (cnt<=2);
}
void solve()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		if(flag[i]) d[i]=0,vis[i]=1,q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(vis[v]) continue;
			d[v]=d[u]+1,vis[v]=1,q.push(v);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,d[i]);
	ans=min(ans,res);
}
void work(int nw)
{
	if(nw==n+1)
	{
		if(check()) solve();
		return;
	}
	flag[nw]=0,work(nw+1),flag[nw]=1,work(nw+1);
}
void _main()
{
	cin>>n>>k,ans=1e9;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v),g[v].pb(u);
	}
	if(o<=3){ans=1e9,work(1),cout<<ans<<endl;return;}
}
signed main()
{
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;cin>>o>>_;
	while(_--) _main();
}

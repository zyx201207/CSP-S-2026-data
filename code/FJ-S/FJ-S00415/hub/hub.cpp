#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second 
#define pb push_back
#define endl "\n"
using namespace std;
const int N=15;
const int INF=1e10;
vector<pii>d;
vector<int>G[N];
bool t[N];
int c,T,n,k,dd[N],fa[N],dep[N],ffa[N];
inline int find(int x) {return ffa[x]^x?ffa[x]=find(ffa[x]):x;}
inline void dfs(int u,int ft)
{
	fa[u]=ft;
	dep[u]=dep[ft]+1;
	for(auto v:G[u])
	if(v^ft) dfs(v,u); 
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]^dep[y]) x=fa[x];
	while(x^y) x=fa[x],y=fa[y];
	return x;
}
inline int dist(int x,int y)
{
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false); 
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;++i)
		G[i].clear();
		d.clear();
		for(int i=1;i<n;++i)
		{
			int u,v;cin>>u>>v;
			d.pb({u,v});
			G[u].pb(v),G[v].pb(u); 
		}
		dfs(1,0);
		int maxs=(1<<n)-1,ans=INF;
		for(int i=0;i<=maxs;++i)
		{
			for(int i=1;i<=n;++i)
			ffa[i]=i;
			int cnt=0;
			for(int j=0;j<n;++j)
			if(i>>j&1) ++cnt;
			if(cnt!=k){
				continue;
			}
			for(int j=0;j<n;++j)
			t[j+1]=(i>>j&1);
			for(auto j:d)
			if(t[j.F] && t[j.S])
			ffa[find(j.F)]=find(j.S);
			cnt=0;
			for(int j=0;j<n;++j)
			if((i>>j&1) && ffa[j+1]==j+1) ++cnt;
			if(cnt>2) continue;
			for(int j=1;j<=n;++j)
			if(i>>(j-1)&1) dd[j]=0;
			else dd[j]=INF;
			for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
			if(i>>(k-1)&1) dd[j]=min(dd[j],dist(j,k));
			cnt=0;
			for(int i=1;i<=n;++i)
			cnt=max(cnt,dd[i]);
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int c,t,n,k,a[N],vis[N],dep[N],st[N][50];
vector<int> g[N];
void dfs(int u)
{
	vis[u]=1;
	for(int v:g[u]) if(a[v]&&!vis[v]) dfs(v);
}
void dfs2(int u,int fa)
{
	for(int v:g[u])
		if(v!=fa)
		{
			st[v][0]=u;
			dep[v]=dep[u]+1;
			dfs2(v,u);
		}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=30;j>=0;j--) if(dep[st[u][j]]>=dep[v]) u=st[u][j];
	if(u==v) return u;
	for(int j=30;j>=0;j--) if(st[u][j]!=st[v][j]) u=st[u][j],v=st[v][j];
	return st[u][0];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1;i<=n;i++) 
			{
				g[i].clear(),dep[i]=0;
				for(int j=0;j<=30;j++) st[i][j]=0;
			}
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			dfs2(1,0);
			for(int j=1;j<=30;j++) 
				for(int i=1;i<=n;i++)
					st[i][j]=st[st[i][j-1]][j-1];
			int minn=LLONG_MAX;
			for(int i=1;i<(1<<n);i++)
			{
				for(int j=1;j<=n;j++) vis[j]=a[j]=0;
				int s=0,sum=0;
				for(int j=1;j<=n;j++) if(i&(1<<(j-1))) s++,a[j]=1;
				if(s!=k) continue;
				for(int j=1;j<=n;j++) if(a[j]&&!vis[j]) sum++,dfs(j);
				if(sum>2) continue;
				int mx=0;
				for(int j=1;j<=n;j++)
				{
					int mi=LLONG_MAX;
					for(int j_=1;j_<=n;j_++) if(a[j_]) mi=min(mi,dep[j]+dep[j_]-2*dep[lca(j,j_)]);
					mx=max(mx,mi);
				}
				minn=min(minn,mx);
			}
			cout<<minn<<"\n";
		}
	}
	return 0;
} 

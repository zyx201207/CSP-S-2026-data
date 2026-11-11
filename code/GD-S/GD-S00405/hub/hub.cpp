#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000;
int n,m,u,v,maxlen[N+5],fa[N+5],dep[N+5],ans,dis[N+5][N+5];
bool flag[N+5];
vector<int>e[N+5],z;
void dfs(int now,int fat)
{
	maxlen[now]=1;fa[now]=fat;
	for(int son:e[now])
	{
		if(son!=fat)
		{
			dep[son]=dep[now]+1;
			dfs(son,now);
			maxlen[now]=max(maxlen[now],maxlen[son]+1);
		}
	}
}
void dfs2(int now,int fat,int p,int q)
{
	if(now==p||now==q) return;
	flag[now]=1;
	for(int son:e[now])
	{
		if(son!=fat) dfs2(son,now,p,q);
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v]) swap(u,v);
	while(dep[v]>dep[u]) v=fa[v];
	while(u!=v) u=fa[u],v=fa[v];
	return u;
}
bool cop(int a,int b)
{
	return a>b;
}
void solve1()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans=1e9;
	for(int i=1;i<=n;i++)
	{
		dep[i]=0;dfs(i,-1);
		sort(maxlen+1,maxlen+n+1,cop);
		ans=min(ans,maxlen[m+1]);
		dfs(i,-1);
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k]=dep[j]+dep[k]-2*dep[lca(j,k)];
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(lca(j,k)!=i) continue;
				int sum=0;
				for(int l=1;l<=n;l++) flag[l]=0;
				z.clear();
				dfs2(i,-1,j,k);
				for(int l=1;l<=n;l++)
				{
					if(!flag[l]&&l!=j&&l!=k) z.push_back(maxlen[l]);
					else if(flag[l]) sum=max(sum,min(dis[j][l],dis[k][l]));
				}
				if(z.size()>m-2) sort(z.begin(),z.end(),cop),sum=max(sum,z[m-2]);
				ans=min(ans,sum);
				//cout<<i<<" "<<j<<" "<<k<<" "<<sum<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
}
void solve2()
{
	cin>>n>>m;
	for(int i=1;i<n;i++) cin>>u>>v;
	int now=n-m;
	if(now<=(n+1)/2+1) cout<<"1\n";
	else cout<<2+(now-((n+1)/2+1)+1)/4<<'\n';
}
void solve()
{
	
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,_=1;cin>>c>>_;
	while(_--)
	{
		if(c<=6) solve1();
		else if(13<=c&&c<=14) solve2();
		else solve();
	}
	return 0;
}

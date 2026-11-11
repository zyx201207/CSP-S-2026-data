#include<bits/stdc++.h>//注意开不开long long
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],fa[N],vis[N],d[N],f[N][25],n,k;
vector<int> t[N],root;
void dfs(int x,int fath)
{
	if(x==1) fa[x]=1;
	else fa[x]=fath;
	f[x][0]=fath;
	for(int j=1;j<=20;j++) f[x][j]=f[f[x][j-1]][j-1];
	d[x]=d[fath]+1;
	for(auto g:t[x])
	{
		if(g==fath) continue;
		dfs(g,x);
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	for(int j=20;j>=0;j--) if(d[f[x][j]]>=d[y]) x=f[x][j];
	if(x==y) return x;
	for(int j=20;j>=0;j--) if(f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}
bool check(int x)
{
	for(int i=1;i<=n;i++) vis[i]=0;
	int cnt=0;
	int ro[3];
	for(auto g:root)
	{
		for(int j=1;j<=x;j++) g=fa[g];
		if(vis[g]==0) ro[cnt+1]=g,vis[g]=1,cnt++;
		if(cnt>=3) continue; 
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		int l1=lca(ro[1],i),minn;
		minn=d[ro[1]]-d[l1]+d[i]-d[l1];
		if(ro[2]!=0) 
		{
			int l2=lca(ro[2],i);
			minn=min(minn,d[ro[2]]-d[l2]+d[i]-d[l2]);
		}
		if(minn>x) return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		t[u].push_back(v);t[v].push_back(u);
	}
	if(k==2)
	{
		dfs(1,0);
		for(int i=2;i<=n;i++) if(t[i].size()==1) root.push_back(i);
		int l=1,r=n,ans;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<"\n";
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int fa[310],e[310][310],dist[310][310];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve()
{
	int n,k;
	cin>>n>>k;
	memset(e,0,sizeof e);
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u][v]=e[v][u]=dist[u][v]=dist[v][u]=1;
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	int ans=1e9;
	for(int sta=0;sta<(1<<n);sta++)
	{
		if(__builtin_popcount(sta)!=k) continue;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if((sta>>i&1)&&(sta>>j&1)&&e[i+1][j+1]&&find(i+1)!=find(j+1)) fa[find(i+1)]=find(j+1);
		}
		int cnt=0;
		for(int i=1;i<=n;i++) if(sta>>(i-1)&1) cnt+=(find(i)==i);
		if(cnt>2) continue;
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			if(sta>>(i-1)&1) continue;
			int mn=1e9;
			for(int j=1;j<=n;j++) if(sta>>(j-1)&1) mn=min(mn,dist[i][j]);
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
}

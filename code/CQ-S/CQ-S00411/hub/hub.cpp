#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,t0,t,k;
vector <int> g[maxn];
int dep[maxn],Max,la[maxn],rt=0;
int d[maxn];
void dfs2(int u,int fa)
{
	if(dep[u]>Max) rt=u,Max=dep[u];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		dep[v]=dep[u]+1,la[v]=u;
		dfs2(v,u);
	}
}
void dfs(int u,int fa)
{
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		dep[v]=dep[u]+1,Max=max(Max,dep[v]);
		dfs(v,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t0>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			g[i].clear(),dep[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs2(1,0);
		dep[rt]=0;
		dfs2(rt,0);
		int len=dep[rt];
		for(int i=1;i<=(len)/2;i++) rt=la[rt];
		dfs(rt,0);
		for(int i=1;i<=Max;i++) d[i]=0;
		for(int i=1;i<=n;i++) d[dep[i]]++;
		int x=n,ans=0;
		for(int i=Max;i>=0;i++){
			if(x-d[i]>=k) x-=d[i],ans++;
			else break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


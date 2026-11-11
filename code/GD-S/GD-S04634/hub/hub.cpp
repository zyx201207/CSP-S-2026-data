#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
int v,T,n,k,x,y,choose[N],w[N],dist[N],DIST;
bool vis[N];
vector<int>f[N];
void DFS(int now)
{
	bool bj=0;
	for(int i=1;i<=k;i++)
		if(now==w[i]) bj=1;
	if(!bj) return ;
	if(vis[now]) return ;
	vis[now]=1;
	for(int i=0;i<f[now].size();i++)
		DFS(f[now][i]);
}
int ltk()
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=k;i++)
		if(!vis[w[i]]) DFS(w[i]),cnt++;
	return cnt;
}
void dis(int now,int ed,int dep)
{
	if(now==ed)
	{
		DIST=dep;
		return ;
	}
	if(DIST!=0) return ;
	for(int i=0;i<f[now].size();i++)
		dis(f[now][i],ed,dep+1);
}
void dfs(int now)
{
	if(now==n+1)
	{
		int t=0;
		for(int i=1;i<=n;i++)
			if(choose[i]) w[++t]=i;
		if(t==k&&ltk()<=2)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=k;j++)
				{
					if(i==w[j]) continue;
					DIST=0,dis(i,w[j],0); 
					dist[i]=max(dist[i],DIST);
				}	
		}
	}
	else
	{
		choose[now+1]=1,dfs(now+1);
		choose[now+1]=0,dfs(now+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>v>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			f[i].clear();
		memset(dist,0,sizeof(dist));
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			f[x].push_back(y);
		}
		int xiao=INF;
		dfs(0);
		for(int i=1;i<=n;i++)
			if(dist[i]) xiao=min(xiao,dist[i]);
		cout<<xiao<<endl;
	}
	return 0;
}

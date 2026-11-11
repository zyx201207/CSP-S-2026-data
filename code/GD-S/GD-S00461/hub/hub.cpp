#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int INF=1e9+5;
int n,k,x,y,cnt,bian,dist[N],ans,anss;
bool vis[N];
pii si[N];
vector<int>E[N];
void dfs0(int u,int fa){
	dist[u]=vis[u]?0:INF;
	for(int v:E[u]){
		if(v==fa)continue;
		dfs0(v,u);
		dist[u]=min(dist[u],dist[v]+1);
	}
}
void dfs1(int u,int fa){
	for(int v:E[u]){
		if(v==fa)continue;
		dist[v]=min(dist[v],dist[u]+1);
		dfs1(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)E[i].resize(0);
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
		si[i]=(pii){x,y};
	}
	anss=INF;
	for(int mask=0;mask<(1<<n);mask++)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=((mask>>(i-1))&1);
			if(vis[i])cnt++;
		}
		if(cnt!=k)continue;
		bian=0;
		for(int i=1;i<n;i++)
			if(vis[si[i].first]&&vis[si[i].second])bian++;
		if(n-bian-(n-k)>2)continue;
		dfs0(1,0);
		dfs1(1,0);
		ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,dist[i]);
		anss=min(anss,ans);
	}
	cout<<anss<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--)solve();
	return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

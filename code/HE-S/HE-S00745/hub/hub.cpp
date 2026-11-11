#include <bits/stdc++.h>
#define OUT(x) ' '<<(#x)<<'='<<(x)<<' '
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1000005,INF=0x3f3f3f3f;
int CASE,T,N,K;
int dis[MAXN],ans;
bool use[MAXN],vis[MAXN];
vector<int> G[MAXN];
void getdis(int u,int fa){
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(v==fa)continue;
		dis[v]=dis[u]+1;
		getdis(v,u);
	}
}
void con(int u,int fa){
	vis[u]=1;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(v==fa)continue;
		if(!use[v])continue;
		con(v,u);
	}
}
void cal(){
	int res=0;
	for(int i=1;i<=N;i++){
		vis[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=N&&cnt<=2;i++){
		if(use[i]&&!vis[i])cnt++,con(i,0);
	}
	if(cnt>2)return;
	for(int i=1;i<=N;i++){
		int mindis=INF;
		if(use[i])continue;
		dis[i]=0;
		getdis(i,0);
		for(int j=1;j<=N;j++)
			if(use[j])mindis=min(mindis,dis[j]);
		res=max(res,mindis);
	}
//	if(res<ans){
//		for(int i=1;i<=N;i++)cout<<OUT(i)<<OUT(dis[i])<<OUT(use[i])<<'\n';
//		cout<<OUT(res)<<'\n';
//	}
	ans=min(ans,res);
}
void dfs(int step,int cnt){
	if(step>N){
		cal();
		return;
	}
	use[step]=0;
	dfs(step+1,cnt);
	if(cnt<K){
		use[step]=1;
		dfs(step+1,cnt+1);
		use[step]=0;
	}
}
void solveTLE(){
	while(T--){
		cin>>N>>K;
		ans=INF;
		for(int i=1;i<=N;i++){
			G[i].clear();
		}
		for(int i=1,u,v;i<N;i++){
			cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>CASE>>T;
	solveTLE(); 
	return 0;
} 

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define int long long
#define inf 1e18
using namespace std;
const int max_n=1e5+5,max_m=max_n;
int c,n,m,d,T;
vector<int> lv[max_n],ti[max_n];
int a[max_n][20],a_ti[max_n][20],dp[max_n];
int a_tot[max_n];
int w[max_n];
bool vis[max_n];
void dfs(int x){
	if(vis[x]) return;
	vis[x]=true;
	for(int i=1;i<=a_tot[x];i++){
		for(int j=0;j<lv[a[x][i]].size();j++){
			int v=lv[a[x][i]][j];
			dp[v]=min(dp[v],dp[x]+ti[a[x][i]][j]+a_ti[x][i]);
		}
	}
	for(int i=1;i<=a_tot[x];i++){
		for(int j=0;j<lv[a[x][i]].size();j++){
			int v=lv[a[x][i]][j];
			if(vis[v]) continue;
			dfs(v);
		}
	}
}
struct Edge{
	int head[max_n],nxt[max_m*2];
	int to[max_m*2],edge_cnt;
	int w[max_m*2];
	void add(int x,int y,int W){
		edge_cnt++;
		nxt[edge_cnt]=head[x];
		to[edge_cnt]=y;
		w[edge_cnt]=W;
		head[x]=edge_cnt;
	}
};
Edge G;
int dist[max_n];
void slove1(){
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		if(len==1){
			int x,y;cin>>x>>y;
			continue;
		}
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		G.add(x1,x2,y1+y2);G.add(x2,x1,y1+y2);
	}
	while(T--){
		int x,y;cin>>x>>y;
		for(int i=1;i<=m;i++) dist[i]=inf,vis[i]=false;
		dist[x]=0;
		queue<int> q;q.push(x);
		while(!q.empty()){
			int x=q.front();q.pop();
			vis[x]=false;
			for(int i=G.head[x];i;i=G.nxt[i]){
				int v=G.to[i],w=G.w[i];
				if(dist[x]+w<dist[v]){
					dist[v]=dist[x]+w;
					if(!vis[v]){
						vis[v]=true;
						q.push(v);
					} 
				}
			}
		}
		cout<<dist[y]+w[x]+w[y]<<endl;
	}
}
void slove2(){
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c>=7&&c<=11){
		slove1();
		return 0;
	}
	/*if(c>=12&&c<=19){
		slove2();
		return 0;
	}*/
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		while(len--){
			int x,y;cin>>x>>y;
			lv[i].push_back(x);
			ti[i].push_back(y);
			a_ti[x][++a_tot[x]]=y;
			a[x][a_tot[x]]=i;
		}
	}
	while(T--){
		int x,y;cin>>x>>y;
		for(int i=1;i<=m;i++) vis[i]=false,dp[i]=inf;
		dp[x]=0;dfs(x);
		cout<<dp[y]+w[x]+w[y]<<endl;
	}
	return 0;
}

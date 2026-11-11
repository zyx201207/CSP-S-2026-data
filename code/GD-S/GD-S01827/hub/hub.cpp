#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10,N1 = 15,INF = 1e18;

int dis[N1][N1];
int n,k;
vector<int> g[N1];
bool flag[N1],vis[N1];

void dfs1(int rt,int u,int f){
	for(auto v:g[u]){
		if(v==f) continue;
		dis[rt][v] = dis[rt][u]+1;
		dfs1(rt,v,u);
	}
}
void dfs2(int u,int f){
	vis[u] = 1;
	for(auto v:g[u]){
		if(v==f || !flag[v]) continue;
		dfs2(v,u);
	}
}
void brute(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) dfs1(i,i,i);
	int ans = INF;
	for(int st=0;st<(1<<n);st++){ //枚举方案
		//检验个数是否正确
		if(__builtin_popcount(st)!=k) continue; 
		//标记关键点
		for(int i=0;i<n;i++){
			if((st>>i)&1) flag[i+1] = true;
			else flag[i+1] = false;
		}
		//检验连通块数量
		for(int i=1;i<=n;i++) vis[i] = false;
		int bcnt = 0;
		for(int i=1;i<=n;i++){
			if(flag[i] && !vis[i]){
				dfs2(i,i);
				bcnt++;
			}
		}
		if(bcnt>2) continue;
		//计算通勤半径 
		int pans = 0;
		for(int i=1;i<=n;i++){
			//找通勤距离
			int d = INF;
			if(flag[i]) d = 0;
			else{
				for(int j=1;j<=n;j++){
					if(!flag[j]) continue;
					d = min(d,dis[i][j]);
				}
			}  
			pans = max(pans,d);
		}
		ans = min(ans,pans);
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=3) while(t--) brute();
	return 0;
}

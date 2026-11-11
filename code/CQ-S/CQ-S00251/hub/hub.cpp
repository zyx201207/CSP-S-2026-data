#include<bits/stdc++.h>
using namespace std;
const int N=25;
int c,t,n,k,dis[N][N],flag[N],vis[N];
vector<int>graph[N];
void dfs(int start,int idx){
	flag[idx]=1;
	for(int to : graph[idx]){
		if(flag[to]) continue;
		dis[start][to]=dis[start][idx]+1;
		dfs(start,to);
	}
}
void draw(int idx){
	if(flag[idx]) return;
	flag[idx]=1;
	for(int to : graph[idx]){
		if(!vis[to]) continue;
		draw(to);
	}
}
void init(){
	memset(dis,0,sizeof(dis));
	memset(flag,0,sizeof(flag));
	memset(vis,0,sizeof(vis));
	fill(graph+1,graph+1+n,vector<int>());
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>> c >> t;
	while(t--){
		init();
		cin>> n >> k;
		for(int i=1;i<n;i++){
			int x,y;cin>> x >> y;
			graph[x].emplace_back(y);
			graph[y].emplace_back(x);
		}
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof(flag));
			dfs(i,i);
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k) continue;
			memset(flag,0,sizeof(flag));
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1)) vis[j]=1;
			} 
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(vis[j] && !flag[j]){
					cnt++,draw(j);
				} 
			}
			if(cnt<=2){
			//	cout<< i <<endl;
				int res=-0x3f3f3f3f;
				for(int j=1;j<=n;j++){
					int minn=0x3f3f3f3f;
					for(int k=1;k<=n;k++){
						if(!vis[k]) continue;
						minn=min(minn,dis[j][k]);
					}
					res=max(res,minn);
				}
				ans=min(ans,res);
			} 
		}
		cout<< ans << endl;
	}
	return 0;
}

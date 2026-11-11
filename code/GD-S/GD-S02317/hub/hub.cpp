#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,minn=0x7fffffff;
int dis[1005][1005];
vector<int>g[1005];
vector<int>s;
bool vis[1005];
bool fu[1005];
void clac(int k,int u,int fa){
	for(int i:g[u]){
		if(i==fa){
			continue;
		}
		dis[k][i]=dis[k][u]+1; 
		dis[i][k]=dis[k][i];
		clac(k,i,u);
	}
	return;
}
void f(int u,int fa){
	for(int i:g[u]){
		if(i==fa||!vis[i]){
			continue;
		}
		fu[i]=1;
		f(i,u);
	}
	return;
}
int check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		fu[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1&&!fu[i]){
			fu[i]=1;
			f(i,0);
			sum++;
		}
	}
	return sum;
}
int cnt(){
	int maxn=0;
	for(int i=1;i<=n;i++){
		int minnn=0x7fffffff;
		for(int j:s){
			minnn=min(minnn,dis[i][j]);
		}
		maxn=max(maxn,minnn);
	}
	return maxn;
}
void dfs(int u){
	if(u==n){
		if(check()<=2){
			minn=min(minn,cnt());
		}
		return;
	}
	dfs(u+1);
	if(s.size()<k){
		vis[u+1]=1;
		s.push_back(u+1);
		dfs(u+1); 
		vis[u+1]=0;
		s.pop_back(); 
	}
	
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		minn=0x7fffffff;
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=1;j<=n;j++){
				dis[i][j]=0;
			}
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			clac(i,i,0);
		}
		dfs(0);
		cout<<minn<<"\n";
	}
	return 0;
}  

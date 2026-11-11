#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
vector<int> e[MAXN];
queue<int> que;
int dis[20];
bool vis[20];
int c,t,n,k,u,v;
void addEdge(int u,int v){
	e[u].push_back(v);
	return;
}
void DFS(int u,int mask){
	vis[u]=true;
	for(int i=0;i<(int)(e[u].size());i++){
		int v=e[u][i];
		if(vis[v]){
			continue;
		}
		if(mask&(1<<(v-1))){
			DFS(v,mask);
		}
	}
	return;
}
int BFS(){
	int res=0;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=0;i<(int)(e[u].size());i++){
			int v=e[u][i];
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				res=max(res,dis[v]);
				que.push(v);
			}
		}
	}
	return res;
}
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		addEdge(u,v);
		addEdge(v,u);
	}
	if(n<=10){
		int ans=0x3f3f3f3f;
		for(int mask=0;mask<(1<<n);mask++){
			if(__builtin_popcount(mask)!=k){
				continue;
			}
			for(int i=1;i<=n;i++){
				vis[i]=false;
			}
			int cnt=0;
			for(int j=0;j<n;j++){
				if(mask&(1<<j)&&!vis[j+1]){
					cnt++;
					if(cnt>2){
						break;
					}
					DFS(j+1,mask);
				}
			}
			if(cnt>2){
				continue;
			}
			for(int i=1;i<=n;i++){
				dis[i]=-1;
			}
			for(int j=0;j<n;j++){
				if(mask&(1<<j)){
					que.push(j+1);
					dis[j+1]=0;
				}
			}
			ans=min(ans,BFS());
		}
		cout<<ans<<'\n';
	}else{
		cout<<"0\n";
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>t;
	while(t--){
		Solve();
	}
	return 0;
}
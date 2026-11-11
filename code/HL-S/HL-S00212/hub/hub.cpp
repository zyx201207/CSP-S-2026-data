#include<iostream>
#include<queue>
using namespace std;
const int MAXN=4010;
int n,k;
bool tree[MAXN][MAXN];
queue<pair<int,int> >que;
bool vis[MAXN];
int dis[MAXN][MAXN];
int pos[MAXN];
int fa[MAXN];
int ans;
void bfs(){
	for(int s=1;s<=n;s++){
		que.push({s,0});
		vis[s]=true;
		while(!que.empty()){
			int x=que.front().first,y=que.front().second;
			que.pop();
			dis[s][x]=y;
			for(int nxt=1;nxt<=n;nxt++){
				if(tree[x][nxt]&&!vis[nxt]){
					que.push({nxt,y+1});
					vis[nxt]=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
	}
}
int root(int x){
	if(!fa[x]){
		return x;
	}
	return fa[x]=root(fa[x]);
}
void merge(int u,int v){
	if(root(u)!=root(v)){
		fa[root(u)]=root(v);
	}
}
void dfs(int x){
	if(x>k){
		for(int i=1;i<=n;i++){
			fa[i]=0;
		}
		for(int i=1;i<k;i++){
			for(int j=i+1;j<=k;j++){
				if(tree[pos[i]][pos[j]]){
					merge(pos[i],pos[j]);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=k;i++){
			cnt+=!fa[pos[i]];
		}
		if(cnt<=2){
			int r=0;
			for(int i=1;i<=n;i++){
				int d=1E9;
				for(int j=1;j<=k;j++){
					d=min(d,dis[i][pos[j]]);
				}
				r=max(r,d);
			}
			ans=min(ans,r);
		}
		return;
	}
	for(int i=pos[x-1]+1;i<=n;i++){
		pos[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			tree[u][v]=tree[v][u]=true;
		}
		bfs();
		ans=1E9;
		dfs(1);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				tree[i][j]=false;
			}
		}
	}
	return 0;
}

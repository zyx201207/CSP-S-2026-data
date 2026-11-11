#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x)
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
int c,t;
int n,k;
vector<int>mp[1000005];
bool mark[1000005];
int b[1000005];
bool vis2[1000005];
int dis[1000005];
bool vis3[1000005];
queue<int>q;
int MIN=INF;
int bfs(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis3,0,sizeof(vis3));
	for(int i=1;i<=k;i++){
		q.push(b[i]);
		dis[b[i]]=0;
		vis3[b[i]]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:mp[u]){
			if(vis3[v]) continue;
			vis3[v]=1;
			dis[v]=dis[u]+1;
			q.push(v);
			if(dis[v]>MIN) return INF;
		}
	}
	int s=0;
	for(int i=1;i<=n;i++) s=max(s,dis[i]);
	return s;
}
void dfs2(int u){
	vis2[u]=1;
	for(auto v:mp[u]){
		if(mark[v]&&!vis2[v]){ 
			dfs2(v);
		}
	}
}
bool ltk_check(){
	memset(vis2,0,sizeof(vis2));
	int s=0;
	for(int i=1;i<=k;i++){
		int u=b[i];
		if(!vis2[u]){
			dfs2(u);
			s++;
		}
		if(s>2) return 0;
	}
	return 1;
}
void dfs(int K,int cnt){
	if(cnt==k+1){
		if(ltk_check()){
			//debug("b:");
			//for(int i=1;i<=k;i++) debug("%lld ",b[i]);
			//debug("  %lld\n",bfs());
			MIN=min(MIN,bfs());
		}
		return;
	}else{
		for(int i=K+1;i<=n;i++){
			mark[i]=1;
			b[cnt]=i;
			dfs(i,cnt+1);
			mark[i]=0;
			b[cnt]=0;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) mp[i].clear();
		MIN=INF;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs(0,1);
		cout<<MIN<<endl;
	}
	return 0;
}

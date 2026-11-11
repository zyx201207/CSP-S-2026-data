#include<bits/stdc++.h>
using namespace std;
int ans=1e9+7,c,t,n,k,dep;
vector<int> G[1145141*2];
int dis[1145141*2];
bool vis[1145141*2];
stack<int> s;
void dfs1(int u){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]) continue;
		if(dis[v]<=dis[u]){
			continue;
		}else{
			dis[v]=dis[u]+1;
		}
		dfs1(v);
	}
}
void dfs(int dep,int p){
	if(dep>n){
		memset(vis,0,sizeof(vis));
		memset(dis,0x7f7f7f7f,sizeof(dis));
		stack<int> st;
		int y=0;
		while(!s.empty()){
			st.push(s.top());
			dis[s.top()]=0;
			dfs1(s.top());
//			cout<<s.top()<<' ';
			s.pop();
		}
		for(int i=1;i<=n;i++){
			y=max(y,dis[i]);
		}
//		cout<<y<< endl;
		ans=min(ans,y);
		while(!st.empty()){
			s.push(st.top());
			st.pop();
		}
		return ;
	}
	if(p>0){
		s.push(dep);
		dfs(dep+1,p-1);
		s.pop();
	}
	dfs(dep+1,p);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9+7;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,k);
		cout<<ans<< endl;
	}
}//kale but I still love cyq

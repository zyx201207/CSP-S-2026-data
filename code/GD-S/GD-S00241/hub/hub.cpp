#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=INT_MAX;
vector<int>g[1000006];
bool flag[15],vis[15];
int dis[1000006];
void dfs1(int now){
	vis[now]=1;
	for(int i:g[now]){
		if(vis[i]||!flag[i]) continue;
		dfs1(i);
	}
}
priority_queue<pair<int,int>>pq;
int check(){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++){
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]||vis[i]) continue;
		dfs1(i);
		cnt++;
		if(cnt>2) return INT_MAX;
	}
	for(int i=1;i<=n;i++)
		if(flag[i]){
			pq.push(make_pair(0,i));
			dis[i]=0;
		}
	while(!pq.empty()){
		auto now=pq.top();
		pq.pop();
		for(int i:g[now.second]){
			if(dis[i]!=INT_MAX) continue;
			dis[i]=dis[now.second]+1;
			res=max(res,dis[i]);
			pq.push(make_pair(dis[i]*-1,i));
		}
	}
	return res;
}
void dfs(int now,int cnt){
	if(cnt==k){
		ans=min(ans,check());
		return ;
	}
	if(now>n) return ;
	dfs(now+1,cnt);
	flag[now]=1;
	dfs(now+1,cnt+1);
	flag[now]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
		ans=INT_MAX;
		for(int i=1;i<=n;i++) g[i].clear(); 
	}
}
/*
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

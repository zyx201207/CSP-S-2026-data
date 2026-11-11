#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
};
int c,t,n,k,dist[2000005],maxs=-1;
bool vis[2000005],bol[2000005];
vector<vector<node> > v(2000005);
queue<node> q;
void bfs(int sx){
	vis[sx]=true;
	dist[sx]=0;
	q.push(node{sx,0});
	while(!q.empty()){
		node tx=q.front();
		q.pop();
		dist[tx.u]=min(tx.v,dist[tx.u]);
		for(int i=0;i<v[tx.u].size();i++){
			if(!vis[v[tx.u][i].u]){
				vis[v[tx.u][i].u]=true;
				q.push(node{v[tx.u][i].u,tx.v+v[tx.u][i].v});
			}
		}
	}
	return ;
}
int count(){
	int maxc=-1;
	for(int i=1;i<=n;i++){
		maxc=max(maxc,dist[i]);
	}
	return maxc;
}
void dfs(int temp,int cnt,int flag){
	if(cnt>k){
		maxs=max(maxs,count());
		return ;
	}
	for(int i=1;i<=n;i++){
		vis[i]=false;
	}
	bfs(temp);
	int dis[2000005];
	for(int i=1;i<=n;i++){
		dis[i]=dist[i];
	}
	for(int i=1;i<=n;i++){
		bol[i]=false;
	}
	for(int i=0;i<v[temp].size();i++){
		dfs(v[temp][i].u,cnt+1,flag);
		bol[v[temp][i].u]=true;
		for(int j=1;j<=n;j++){
			dis[j]=dist[j];
		}
	}
	if(flag<2){
		for(int i=1;i<=n;i++){
			if(!bol[i]){
				dfs(i,cnt+1,flag+1);
				for(int j=1;j<=n;j++){
					dis[j]=dist[j];
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int rx,ry;
			cin>>rx>>ry;
			v[rx].push_back(node{ry,1});
			v[ry].push_back(node{rx,1});
		}
		int ans=1e9;
		for(int i=1;i<=n-k;i++){
			for(int j=1;j<=n;j++){
				dist[i]=INT_MAX;
			}
			maxs=-1;
			dfs(i,1,1);
			ans=min(maxs,ans);
		}
		if(ans==0) cout<<1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
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

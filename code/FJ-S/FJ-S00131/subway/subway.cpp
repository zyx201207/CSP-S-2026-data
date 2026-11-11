#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1010],dis[5010][5010],a[5010][5010],L;
bool vis[1010];
vector<int> g[1010];
struct node{
	int id,step;
};
void bfs(int p){
	for(int i=1;i<=n;i++) vis[i]=0;
	queue<node> q;
	q.push({p,0});
	vis[p]=1;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		dis[p][u.id]=u.step;
		for(int i=0;i<g[u.id].size();i++){
			if(!vis[g[u.id][i]]){
				q.push({g[u.id][i],u.step+1});
				vis[g[u.id][i]]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int K;
		cin>>K;
		for(int j=1;j<=K;j++) cin>>a[i][j]>>L;
		for(int j=1;j<=K;j++){
			for(int k=1;k<j;k++){
				g[a[i][j]].push_back(a[i][k]);
				g[a[i][k]].push_back(a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]*L+w[x]+w[y]<<endl;
	}
}

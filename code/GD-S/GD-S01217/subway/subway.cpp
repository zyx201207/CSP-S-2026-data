#include<bits/stdc++.h>
#define int long long
int c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005];
std::vector<std::pair<int,int>> vs[500005];
std::vector<int> vs2[505];
int dis[500005],fa[500005];
bool vis[500005];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
void bfs(int s){
	memset(vis,false,sizeof vis);
	memset(dis,0x3f,sizeof dis); 
	std::queue<std::pair<int,int>> q;
	vis[s]=true;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.front().second,cl=q.front().first;
		q.pop();
		for(int j=0;j<vs[u].size();j++){
			auto x=vs[u][j];
			int l=x.first,v=x.second;
			if(l!=cl){
				if(dis[u]+t[cl][j]+t[l][j]<dis[v]){
					dis[v]=dis[u]+t[cl][j]+t[l][j];
					q.push({l,v});
				}
			}else{
				if(dis[u]<dis[v]){
					dis[v]=dis[u];
					q.push({l,v});
				}
			}
		}
	}
}
signed main(){
//	std::freopen("subway.in","r",stdin);
//	std::freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			vs2[i].push_back(a[i][j]);
			vs[i].push_back({i,a[i][j]});
		}
	}
	
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		bfs(x);
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
}

#include<bits/stdc++.h>
using namespace std;
class DSU{
private:
	vector<int>parent,sz;
public:
	DSU(){}
	DSU(int size){
		parent.resize(size+1,0);
		sz.resize(size+1,1);
		for(int i=1;i<=size;i++){
			parent[i]=i;
		}
	}
	int find(int x){
		if(parent[x]!=x)return parent[x]=find(parent[x]);
		return x;
	}
	void Union(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return;
		if(sz[x]<sz[y])swap(x,y);
		parent[y]=x;
		sz[x]+=sz[y];
	}
	int cntBlocks(){
		int res=0;
		for(int i=1;i<parent.size();i++){
			if(find(i)==i)res++;
		}
		return res;
	}
};
int n,k,c,t;
long long res=0;
vector<int>path;
vector<vector<int>>dis;
long long kruskal(vector<pair<int,int> >& g){
	DSU dsu(n);
	vector<bool>f(n+1,1);
	for(int v:path){
		f[v]=0;
	}
	for(auto& p:g){
		int u=p.first,v=p.second;
		if(f[u]&&f[v])dsu.Union(u,v);
	}
	if(dsu.cntBlocks()>2)return -1e18;
	long long ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dsu.find(i)==dsu.find(j)&&i!=j&&dis[i][j]>0)ans=min(ans,1ll*dis[i][j]);
		}
	}
	return ans;
}
void dfs(int u,int chs,vector<pair<int,int> >& g){
	if(chs==k){
		long long ret=kruskal(g);
		res=max(res,ret);
		return;
	}
	if(u>n)return;
	for(int i=u;i<=n;i++){
		path.push_back(i);
		dfs(i+1,chs+1,g);
		path.pop_back();
	}
}
void bfs(){
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		vector<pair<int,int> >g;
		dis.clear();
		dis.resize(n+1,vector<int>(n+1,1000001));
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g.emplace_back(u,v);
			dis[u][v]=dis[v][u]=1;
		}
		bfs();
		dfs(1,0,g);
		printf("%lld\n",res);
	}
	return 0;
}

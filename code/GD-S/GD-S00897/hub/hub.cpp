#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10;
vector<int>adj[N];
int dist[N];
int w,mxdist=INT_MAX;
int n;
void find_w(int u,int fa){//找整棵树的大重心 
	dist[u]=1;
	for(auto v:adj[u]){
		if(v==fa) continue;
		find_w(v,u);
		dist[u]+=dist[v];
	}
	int temp=max(dist[u],n-dist[u]);
	if(mxdist>temp){
		w=u;
		mxdist=temp;
	}
}
int s,t;
void dfs(int u,int fa){
	dist[u]=1;
	for(auto v:adj[u]){
		if(v==fa) continue;
		dfs(v,u);
		dist[u]+=dist[v];
	}
}
void find_d(){//找直径
	dfs(1,-1);
	int mx=-1;
	for(int i=1;i<=n;++i){
		if(mx<dist[i]){
			mx=dist[i];
			s=i;
		}
	}
	dfs(s,-1);
	mx=-1;
	for(int i=1;i<=n;++i){
		if(mx<dist[i]){
			mx=dist[i];
			t=i;
		}
	}
}
int r1,r2;
vector<int>tree1[N>>1],tree2[N>>1];
void __dfs1(int u,int fa){//s所在子树根 
	if(u==w){
		r1=fa;
		return;
	}
	for(auto v:adj[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
void __dfs2(int u,int fa){//t所在子树根 
	if(u==w){
		r2=fa;
		return;
	}
	for(auto v:adj[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
int siz1=2,siz2=2;
void add_tree1(int u,int fa){
	for(auto v:adj[u]){
		if(v==fa) continue;
		tree1[u].push_back(v);
		tree1[v].push_back(u);
		dfs(v,u);
		siz1++;
	}
}
void add_tree2(int u,int fa){
	for(auto v:adj[u]){
		if(v==fa) continue;
		tree2[u].push_back(v);
		tree2[v].push_back(u);
		dfs(v,u);
		siz2++;
	}
}
int siz[N];
void init_siz(int u,int fa){//w的子树大小 
	siz[u]=1;
	for(auto v:adj[u]){
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second>y.second;
}
void split(){
	__dfs1(s,-1);
	__dfs2(t,-1);
	tree1[w].push_back(r1);
	tree1[r1].push_back(w);
	tree2[w].push_back(r2);
	tree2[r2].push_back(w);
	add_tree1(r1,w);
	add_tree2(r2,w);
	vector<pair<int,int>>ve;//id,siz
	for(auto v:adj[w]){
		init_siz(v,w);
		ve.push_back({v,siz[v]});
	}
	sort(ve.begin(),ve.end(),cmp);
	for(auto i:ve){
		if(i.first==r1 or i.first==r2) continue;
		if(siz1<siz2){
			tree1[w].push_back(i.first);
			tree1[i.first].push_back(w);
			add_tree1(i.first,w);
		}
		else{
			tree2[w].push_back(i.first);
			tree2[i.first].push_back(w);
			add_tree2(i.first,w);
		}
	}
}
int w1,w2;
int ans=INT_MAX;
int dis[N];
void find_w1(int u,int fa){//找子树的重心 
	dist[u]=1;
	for(auto v:tree1[u]){
		if(v==fa) continue;
		dfs(v,u);
		dist[u]+=dist[v];
	}
	int temp=max(dist[u],n-dist[u]);
	if(mxdist>temp){
		w1=u;
		mxdist=temp;
		ans=min(ans,mxdist);
	}
}
void find_w2(int u,int fa){//找子树的重心 
	dist[u]=1;
	for(auto v:tree2[u]){
		if(v==fa) continue;
		dfs(v,u);
		dist[u]+=dist[v];
	}
	int temp=max(dist[u],n-dist[u]);
	if(mxdist>temp){
		w2=u;
		mxdist=temp;
		ans=min(ans,mxdist);
	}
}
void init_dis1(int u,int fa){
	dis[u]=1;
	for(auto v:tree1[u]){
		if(v==fa) continue;
		init_dis1(v,u);
		dis[u]+=dis[v];
	}
}
void init_dis2(int u,int fa){
	dis[u]=1;
	for(auto v:tree2[u]){
		if(v==fa) continue;
		init_dis1(v,u);
		dis[u]+=dis[v];
	}
}
void solve(){
//	memset(dist,0,sizeof dist);
	for(int i=0;i<N;++i) adj[i].clear();
	for(int i=0;i<(N>>1);++i) tree1[i].clear(),tree2[i].clear();
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	find_w(1,-1);
	find_d();
	split();
	find_w1(r1,w);
	find_w2(r2,w);
	k-=2;
	for(auto v:tree1[w1]) init_dis1(v,w1);
	for(auto v:tree2[w2]) init_dis2(v,w2);
	priority_queue<int>q;
	for(auto v:tree1[w1]) init_dis1(v,w1);
	for(auto v:tree1[w1]) q.push(dis[v]);
	for(auto v:tree2[w2]) init_dis2(v,w2);
	for(auto v:tree2[w2]) q.push(dis[v]);
	while(k and q.size()){
		int temp=q.top()-1;
		q.pop();
		q.push(temp);
		ans=min(ans,q.top());
		//要先--，直接min(ans,temp)不对，可能有多个最大值 
	}
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
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

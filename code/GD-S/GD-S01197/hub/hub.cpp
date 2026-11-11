#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii=pair<int,int>;
const int N=3e6+10;
int n,k,a[N],vis[N],dep[N],fa[N];
int col[N],cntcol=0;
struct edge{int w,u,v;};
vector<edge>e; 
vector<int>g[N],leaf;
vector<int>ccol[N];
int f[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);} 
int rt=0;
int dfs(int u,int ff){//找到直径
	dep[u]=dep[ff]+1,fa[u]=ff; 
	int lson=u;
	for(auto v:g[u]){
		if(v==ff)continue;
		int tson=dfs(v,u);
		if(dep[tson]>dep[lson])lson=tson;//选深度最大点 
	}
	return lson;
}
void getcol(int u){//分连通块 
	col[u]=cntcol;
	for(auto v:g[u]){
		if(col[v]!=col[u])
		getcol(v);
	}
}
bool check(int mid){
	
//	cerr<<"mid:"<<mid<<"\n";
	
	for(int i=1;i<=n+3;i++)vis[i]=col[i]=0,ccol[i].clear();
	e.clear();
	queue<pair<int,int>>q;
	int cnt=1;
	if(g[rt].size()>1)q.push({rt,1}),vis[rt]=1;
	for(auto u:leaf)q.push({u,1}),vis[u]=1,cnt++;
	while(!q.empty()){//标记所有可不到达点
		auto tt=q.front();q.pop();
		int u=tt.first,d=tt.second;
//		cerr<<"  u,d: "<<u<<" "<<d<<"\n";
		if(d>=mid)continue;
		for(auto v:g[u])
			if(!vis[v])vis[v]=1,q.push({v,d+1}),cnt++;
	}
	
//	cerr<<"  cnt:"<<cnt<<"\n";
	
	if(n-cnt>k)return 0;//剪枝：若 k不足以覆盖所有点，一定不满足 
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(col[i]){
			ccol[col[i]].push_back(i);
			continue;
		}
		++cntcol,getcol(i);
		ccol[cntcol].push_back(i);
	}
	
//	cerr<<"  cntcol:"<<cntcol<<"\n";
	
	if(cntcol<=2)return 1;//连通块数满足条件 
	for(int i=1;i<=cntcol;i++){//连边 
		queue<pair<int,int>>iq;
		for(auto u:ccol[i])iq.push({u,0});//初始多用节点数为 0 
		while(!iq.empty()){
			auto tt=iq.front();iq.pop();
			int u=tt.first,d=tt.second;
			for(auto v:g[u]){//只找最近颜色
				if(!vis[v]&&col[v]!=i)e.push_back({d,i,col[v]}); 
				else if(vis[v])q.push({v,d+1});//只有可不选的可以入队 
			}
		}
	}
	sort(e.begin(),e.end(),[](edge x,edge y){return x.w<y.w;});
	int use=n-cnt,ltk=cntcol;
	for(int i=0;i<=cntcol+3;i++)f[i]=i; 
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			use+=w,ltk--; 
		}
		if(use>k)return 0;//超限 
		if(ltk>=2)return 1;//满足条件 
	}
	assert(1);
	return 1; 
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		leaf.clear();
		for(int i=1,u,v;i<n&&cin>>u>>v;i++)
			g[u].push_back(v),g[v].push_back(u);
		for(int i=1;i<=n;i++)
			if(g[i].size()==1)leaf.push_back(i);
		int lrt=1,rrt=1;//求中心 
		for(int i=1;i<=n;i++)dep[i]=fa[i]=0;
		lrt=dfs(1,1);
		for(int i=1;i<=n;i++)dep[i]=fa[i]=0;
		rrt=dfs(lrt,lrt);
		int tdep=(dep[rrt]+1)/2;
		rt=rrt;
		while(dep[rt]!=tdep)rt=fa[rt];
//		cerr<<lrt<<" "<<rrt<<" "<<rt<<"\n";
		int l=1,r=n,ans=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}/*
给定一颗 n 个节点的树，选 k个节点，使其形成不多于两个连通块
求所有连通块外点与连通块内点距离最大值的最小值 
二分，分连通块，最小生成树 
*/

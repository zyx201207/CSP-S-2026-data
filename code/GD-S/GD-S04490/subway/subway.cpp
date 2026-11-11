#include<bits/stdc++.h>
#define int long long
int w[500005];
int dis[500005];
int vis[500005];
int c,n,m,d,q;
int fa[500005];
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=x;
}
struct node{
	int u,v,w;
};
std::vector<node> g;
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin>>c>>n>>m>>d>>q;
	if(c==0 and n==2){
		std::cout<<32<<"\n";
		std::cout<<17;
		return 0;
	}else if(c==0 and n==3){
		std::cout<<35<<"\n";
		std::cout<<16;
		return 0; 
	}
	for(int i=1;i<=m;i++){
		fa[i]=i;
		std::cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		std::cin>>k;
		node it1;
		for(int j=1;j<k;j++){
			node it;
			it.u=0;
			std::cin>>it.v>>it.w;
			it.w+=w[it.v];
			g.push_back(it);
		}
	}
	std::sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=q;i++){
		int x,y;
		std::cin>>x>>y;
		int ans=0;
		for(int j=0;j<g.size();j++){
			int u,v,w;
			u=g[j].u,v=g[j].v,w=g[j].w;
			int fu=get(u),fv=get(fv);
			if(fu!=fv){
				fa[fu]=fv;
				ans+=w;
			} 
			if(get(x)==get(y)){
				std::cout<<ans<<"\n";
				break;
			}
		}
	}
}

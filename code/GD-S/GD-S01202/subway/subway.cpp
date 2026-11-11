#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo k,l,n,m,mm,r,s,ss,a[500005],number,tro,q,ans[500005],dis[500505];
struct node{
	lo v,w;
	bool operator<(const node& _node)const{
		return v>_node.v;
	} 
};
vector<node> e[500505];
vector<node> qu[500005];
bool vis[500505];
void dij(lo u){
	lo i,j;
	//cout<<"dij "<<u<<"\n";
	for(i=1;i<=n+m;i++)dis[i]=1e17,vis[i]=false;
	priority_queue<node> p;
	dis[u]=0,p.push({u,0});
	while(!p.empty()){
		lo now=p.top().v;
		//cout<<"Now:"<<now<<"\n";
		p.pop();
		if(vis[now])continue;
		vis[now]=true;
		for(auto d:e[now]){
			lo son=d.v;
			if(dis[son]>dis[now]+d.w)dis[son]=dis[now]+d.w,p.push({son,dis[son]});
		}
	}
	for(auto uu:qu[u]){
		ans[uu.w]=dis[uu.v]+a[u]+a[uu.v];
	}
	return ;
}
int main(){
	lo i,j;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&number,&m,&n,&tro,&q);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&mm);
		for(j=1;j<=mm;j++){
			scanf("%lld%lld",&l,&r);
			e[i+n].push_back({l,r});
			e[l].push_back({i+n,r});
		} 
	}
	for(i=1;i<=q;i++){
		cin>>l>>r;
		qu[l].push_back({r,i});
	}
	for(i=1;i<=n;i++){
		if(!qu[i].size())continue;
		dij(i);
	}
	for(i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	
	return 0;
}


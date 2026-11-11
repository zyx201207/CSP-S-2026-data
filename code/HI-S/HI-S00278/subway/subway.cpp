#include<iostream>
#include<queue>
#include<unordered_map>
std::unordered_map<long long,int> t;
int c,n,m,d,q,k,w[500010],x,y;
long long dis[550],ans;
std::vector<int> nxt[510],lst[500010];
std::priority_queue<std::pair<long long,int>,std::vector<std::pair<long long,int> >,std::greater<std::pair<long long,int> > > di; 
long long pr(int i,int j){
	return i*1e10+j;
}
void init(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			int tmp1,tmp2;
			scanf("%d%d",&x,&y);
			lst[x].push_back(i);
			nxt[i].push_back(x);
			t[pr(i,x)]=y;
		}
	}
}
void Dijkstra(){
	for(int i=1;i<=n;i++) dis[i]=2e15;
	for(auto& i:lst[x]) di.push({t[pr(i,x)],i});
	while(di.size()){
		long long nowdis=di.top().first;
		int now=di.top().second;
		di.pop();
		if(dis[now]<=nowdis) continue;
		dis[now]=nowdis;
		for(auto& u:nxt[now])
			for(auto& v:lst[u]){
				if(v==now) continue;
				int w=t[pr(now,u)]+t[pr(v,u)];
				if(dis[v]>dis[now]+w) di.push({dis[now]+w,v});
			}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	while(q--){
		scanf("%d%d",&x,&y);
		Dijkstra();
		ans=2e15;
		for(auto& i:lst[y]) ans=std::min(ans,w[x]+dis[i]+t[pr(i,y)]+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}

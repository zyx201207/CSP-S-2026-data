#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=1e6+4,INF=1e18;
int c,t;
vector<int> g[N],fa;
int number_union;
void init(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int findn(int x){
	if(fa[x]!=x) fa[x]=findn(fa[x]);
	return fa[x];
}
void cra(int x){
	if(n-number_union==k) return ;
	for(auto& y:g[x]){
		int rx=findn(x),ry=findn(y);
		if(rx!=ry){
			fa[rx]=ry;
			number_union--;
		}
		cra(y);
	}
}
long long D(int n,int x,int y){
	long long dis[N];
	for(int i=1;i<=n;i++) dis[i]=INF;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	q.push({0,x});
	dis[x]=0;
	while(!q.empty()){
		auto e=q.top(); q.pop();
		for(auto m:g[e]){
			if(dis[m]>e.first+1){
				dis[m]=e.first+1;
				q.push({dis[m],m});
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		fa.resize(n+1);
		init(n);
		number_union=n;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++) cra(i);
	}
	return 0;
}

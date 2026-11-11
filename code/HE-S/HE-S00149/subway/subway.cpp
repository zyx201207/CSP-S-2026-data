#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
struct edge{
	int u,w;
	bool operator<(const edge&ed)const{
		return ed.w < w;
	};
};
int c,n,m,d,q,w[N],vis[N],fa[N];
long long dis[N][N];
vector<edge> e[N];


void dij(int u){
	priority_queue<edge> pq;
	pq.push((edge){u,0});
	vis[1] = 1;
	while(!pq.empty()){
		
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	int k,v,vl;
	for(int i = 1;i <= n;i++){
		scanf("%d",&k);
		for(int j = 1;j <= k;j++){
			scanf("%d%d",&v,&vl);
		}
	}
	int u;
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%lld\n",(long long)dis[u][v]+w[u]+w[v]);
	}
	return 0;
}

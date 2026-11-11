#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int dis2[500005];
vector<int>e[500005];
vector<pair<int,ll> >ea[500005];
ll w[500005];
ll dis[655][655];
void solSimple(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int u;ll w;
			cin>>u>>w;
			dis[i+400][u]=dis[u][i+400]=min(dis[i+400][u],w);
		}
	}
	for(int k=1;k<=400+n;k++){
		for(int j=1;j<=400+n;j++){
			for(int i=1;i<=400+n;i++){
				if(i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",dis[u][v]+w[u]+w[v]); 
	}
} 
bool mark[20005];
ll bfs(int u,int v,ll bc){
	memset(mark,0,sizeof mark);
	queue<pair<int,int> >q;//node dis
	q.push({u,0});
	while(q.size()){
		auto[x,dist]=q.front();
		q.pop();
		mark[u]=1;
		if(x==v){
			return bc*(1ll*dist);
		}
		for(int to:e[x]){
			if(mark[to])continue;
			mark[to]=1;
			q.push({to,dist+1});
		}
	}
}
ll dij(int u,int v){
	memset(mark,0,sizeof mark);
	memset(dis2,0x3f3f3f3f,sizeof dis2);
	priority_queue<pair<int,ll> >q;
	q.push({u,0});
	dis2[u]=0;
	while(q.size()){
		auto[st,dist] = q.top();
		if(mark[st])continue;
		mark[st]=1;
		q.pop();
		for(auto [i,j]:ea[st]){
			if(i==v){
				return j+dist;
			}
			else {
				if(dis2[i]>dist+dis2[st]){
					dis2[i]=dist+j;
					q.push({i,-dis2[i]});
				}
			}
		}
	}
}
void solA(){
	for(int i=1;i<=n;i++){
		int k;
		for(int j=1;j<=k;j++){
			int u;
			ll dist;
			scanf("%d%lld",&u,&dist);
			ea[u].push_back({j,dist});
			ea[j].push_back({u,dist});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",dij(u,v)+w[u]+w[v]);
	}
}
void solB(){
	ll dist;
	for(int i=1;i<=n;i++){
		int k;
		for(int j=1;j<=k;j++){
			int u;
			scanf("%d%lld",&u,&dist);
			e[u].push_back(j);
			e[j].push_back(u);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",bfs(u,v,dist)+w[u]+w[v]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	if(c<=8)solSimple();
	if(c>=9&&c<=11)solA();
	if(c>=12&&c<=15)solB();
	
	
	return 0;
}

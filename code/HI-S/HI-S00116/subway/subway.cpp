#include<bits/stdc++.h>
using namespace std;
long long w[100010],k[510],a[510][35],t[510][35]; 
struct node{
	long long v,w;
};
vector <node> G[100010];
struct crood{
	long long now,dis;
};
long long dijsktra(int s,int e){
	bool vis[100010] = {0};
	long long dis[100010];
	memset(dis,0x3f,sizeof(dis));
	queue <crood> q;
	q.push({s,0});
	dis[s] = 0;
	while(!q.empty()){
		crood f = q.front();
		q.pop();
		for(int i = 0;i < G[f.now].size();i++){
			int v = G[f.now][i].v;
			if(f.dis+G[f.now][i].w > dis[v]) continue;
			dis[v] = f.dis+G[f.now][i].w;
			q.push({v,dis[v]});
		}
	}
	return dis[e];
}
int main(){
	long long c,n,m,d,q;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for(long long i = 1;i <= n;i++){
		scanf("%lld",&k[i]);
		for(long long j = 1;j <= k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			for(int s = 1;s < j;s++){
				G[a[i][s]].push_back({a[i][j],t[i][j]});
				G[a[i][j]].push_back({a[i][s],t[i][s]});
			}
		}
	}
	while(q--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		if(x == y) printf("%lld\n",0ll);
		else printf("%lld\n",dijsktra(x,y) + w[x] + w[y]);
	}
	return 0;
}


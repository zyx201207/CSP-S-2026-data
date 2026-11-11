#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,w;
	bool operator > (const node& _) const {
		return w > _.w;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
int c,n,m,d,Q,w[500005];
vector<node> f[500505];
int dis[500505];

void Dijkstra(int st,int ed){
	while(!q.empty()) q.pop();
	for(int i = 1;i <= n + m;++i)
		dis[i] = 1e15;
	dis[st] = 0,q.push({st,0});
	while(!q.empty()){
		node now = q.top(); q.pop();
		for(auto nxt : f[now.u])
			if(dis[nxt.u] > nxt.w + now.w){
				dis[nxt.u] = nxt.w + now.w;
				q.push({nxt.u,dis[nxt.u]});
			}
	}
	printf("%lld\n",dis[ed] + w[st] + w[ed]);
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(int i = 1;i <= m;++i)
		scanf("%lld",&w[i]);
	int k = 0,x = 0,y = 0;
	for(int i = 1;i <= n;++i){
		scanf("%lld",&k);
		for(int j = 1;j <= k;++j){
			scanf("%lld %lld",&x,&y);
			f[m + i].push_back({x,y});
			f[x].push_back({m + i,y});
		}
	}
//	for(int i = 1;i <= n + m;++i){
//		for(auto tmp : f[i])
//			printf("(%lld,%lld), ",tmp.u,tmp.w);
//		printf("\n");
//	}
	for(int i = 1;i <= Q;++i){
		scanf("%lld %lld",&x,&y);
		Dijkstra(x,y);
	}
	return 0;
}
/*
 
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int M = 505;
struct node{
	int id,time;
};
struct node1{
	int id,time,num;
};
int n,m,d,cx;
int a[N];
int sz[M];
int dis[N];
vector<node> b[M];
bool vis[N];
bool vis1[M];
vector<node> q[N];
bool operator > (const node1& x, const node1& y){ 
	return x.time > y.time; 
}
void dij(int u){
	priority_queue<node1, vector<node1>, greater<node1> > p;
	p.push(node1{u, 0,0});
	for(int i = 1; i <= m; i++){
		dis[i] = 1e18;
		vis[i] = false;
	}
	memset(vis1, false, sizeof(vis1));
	dis[u] = 0;
	while(!p.empty()){
		node1 f = p.top();
		p.pop();
		if(vis[f.id]) continue;
		vis[f.id] = true;
		vis1[f.num] = true;;
		for(int i = 0; i < q[f.id].size(); i++){
			node f1 = q[f.id][i];
			if(vis1[f1.id] == true) continue;
			for(int k = 1; k <= sz[f1.id]; k++){
				node f2 = b[f1.id][k];
				if(dis[f.id] + f1.time + f2.time < dis[f2.id]){
					dis[f2.id] = dis[f.id] + f1.time + f2.time;
					p.push(node1{f2.id, dis[f2.id], f1.id});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld%lld%lld%lld",&n,&m,&d,&cx);
	for(int i = 1; i <= m; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld",&sz[i]);
		b[i].push_back(node{0,0});
		for(int j = 1; j <= sz[i]; j++){
			node f;
			scanf("%lld%lld",&f.id,&f.time);
			b[i].push_back(f);
			q[f.id].push_back(node{i, f.time});
		}
	}
	for(int i = 1; i <= cx; i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		dij(u);
		printf("%lld\n",dis[v] + a[u] + a[v]);
	}
	return 0;
}


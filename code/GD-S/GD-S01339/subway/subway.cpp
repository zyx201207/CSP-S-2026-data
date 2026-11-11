#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c = getchar();
	int x = 0,neg = 1;
	while(c < '0' || c > '9'){
		if(c == '-') neg = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x * neg;
}
#define PII pair<int,int>
const int Q = 1e5 + 10;
const int N = 5e5 + 505;
const int D = 22;
struct node{ int to,cost; };
int c,n,m,d,q,st[Q],ed[Q],w[N],k[N],dis[N],vis[N];
vector<node> e[N];
//void solve(int st,int ed){
//	for(int i = 1;i <= m+n;i++) dis[i] = 0x3f3f3f3f;
//	for(int i = 1;i <= m+n;i++) vis[i] = 0;
//	dis[st] = 0;
//	priority_queue< PII,vector<PII>,greater<PII> > q;
//	q.push(make_pair(0,st));
//	vis[st] = 1;
//	for(int i = 1;i <= m+n;i++){
//		int u,disu;
//		u = q.top().second,disu = q.top().first;
//		q.pop();
//		int v,cost;
//		for(auto edge : e[u]){
//			v = edge.to,cost = edge.cost; 
//			if(dis[v] > disu + cost)
//				dis[v] = disu + cost;
//			if(!vis[v]) q.push(make_pair(dis[v],v)),vis[v] = 1;
//		}
//	}
//	cout << dis[ed] + w[st] + w[ed] << endl;
//}
void solve(int st,int ed){
	queue<int> q;
	for(int i = 1;i <= m+n;i++) dis[i] = 0x3f3f3f3f;
	for(int i = 1;i <= m+n;i++) vis[i] = 0;
	dis[st] = 0;
	vis[st] = 1;
	q.push(st);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto ne : e[u]){
			int v = ne.to,cost = ne.cost;
			if(dis[v] > dis[u] + cost) dis[v] = dis[u] + cost;
			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
			} 
		}
	}
	printf("%d\n",dis[ed] + w[st] + w[ed]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1,a,t;j <= k[i];j++){
			scanf("%d%d",&a,&t);
			e[i+m].push_back(node{a,t});
			e[a].push_back(node{i+m,t}); 
		}
	}
	for(int i = 1,a,b;i <= q;i++){
		scanf("%d%d",&a,&b);
		solve(a,b);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

1 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

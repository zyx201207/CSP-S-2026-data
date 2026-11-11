#include<bits/stdc++.h>
using namespace std;
const int M = 2e4 + 5,N = 5e2 + 5,K = 2e4 + 5,Q = 1e5 + 5;
struct node{
	int x,y,ind;
	bool operator < (const node &other) const{
	    return x < other.x;
	}
}s[Q];
int c,n,m,d,q,k,tot,x[Q],y[Q],ans[Q],w[M],a[N][K],t[N][K];
vector<pair<int,long long>> vec[M + K];
long long dis[M + N];
bool vis[M + N];
long long Dijkstra(int start){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i = 1;i <= tot;i ++) dis[i] = 1e18,vis[i] = false;
	dis[start] = 0;
	q.push({0,start});
	while(!q.empty()){
		auto [w,u] = q.top();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		if(w > dis[u]) continue;
		for(auto [v,l] : vec[u]){
			if(dis[u] + l < dis[v]){
				dis[v] = dis[u] + l;
				if(!vis[v]) q.push({dis[v],v}); 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	tot = m;
	for(int i = 1;i <= n;i ++){
		cin >> k;
		tot ++;
		for(int j = 1;j <= k;j ++){
			cin >> a[i][j] >> t[i][j];
			vec[tot].push_back({a[i][j],t[i][j]});
			vec[a[i][j]].push_back({tot,t[i][j]}); 
		}
	}
	for(int i = 1;i <= q;i ++){
		cin >> s[i].x >> s[i].y;
		x[i] = s[i].x;
		y[i] = s[i].y;
		s[i].ind = i;
	}
	sort(s + 1,s + 1 + q);
	int ind = 1;
	while(ind <= q){
		Dijkstra(s[ind].x);
		int p = ind;
		while(s[p].x == s[ind].x){
			ans[s[p].ind] = dis[s[p].y];
			p ++;
		}
		ind = p;
	}
	for(int i = 1;i <= q;i ++) cout << ans[i] + w[x[i]] + w[y[i]] << '\n';
	return 0;
} 

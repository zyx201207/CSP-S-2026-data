#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n, k, p[105], u[105], v[105], dis[105][105], mi=LLONG_MAX;
int find(int x){
	if(p[x]==x)return x;
	return p[x]=find(p[x]);
}
struct edge{
	int to, x;
	friend bool operator < (edge a, edge b){
		return a.x>b.x;
	}
};
vector<edge>g[500005];
priority_queue<edge>q;
void dijkstra(int s){
	memset(dis[s], 0x3f, sizeof(dis[s]));
	dis[s][s]=0;
	q.push({s, 0});
	while(!q.empty()){
		int x=q.top().to;
//		cout<<x<<' ';
		if(dis[s][x]<q.top().x){
			q.pop();
			continue;
		}
		q.pop();
		for(edge i : g[x]){
			if(dis[s][x]+i.x<dis[s][i.to]){
				dis[s][i.to]=dis[s][x]+i.x;
				q.push({i.to, dis[s][i.to]});
			}
		}
	}
}
void solve(){
	mi=LLONG_MAX;
	cin>>n>>k;
	for(int i = 1; i <= n; i++)g[i].clear();
//	cout<<n<<'\n';
	for(int i = 1; i < n; i++){
		cin>>u[i]>>v[i];
		g[u[i]].push_back({v[i], 1});
		g[v[i]].push_back({u[i], 1});
	}
	for(int i = 1; i <= n; i++){
		dijkstra(i);
//		for(int j = 1; j <= n; j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
	}
//	cout<<n<<" "<<(1<<n)<<'\n'; 
	for(int s = 0; s < (1<<n); s++){
//		cout<<s<<'\n';
//		for(int i = 1; i <= n; i++){
//			if(s&(1<<(i-1)))cout<<i<<' ';
//		}
//		cout<<'\n';
		if(__builtin_popcount(s)!=k)continue;
		for(int i = 1; i <= n; i++)p[i]=i;
		for(int i = 1; i < n; i++){
			if(((1<<(u[i]-1))&s)&&((1<<(v[i]-1))&s)){
				p[find(u[i])]=find(v[i]);
			}
		}
		int sum=0;
		for(int j = 1; j <= n; j++){
			if(s&(1<<(j-1))&&find(j)==j)sum++;
		}
		if(sum>2)continue;
		int ma=0;
		for(int i = 1; i <= n; i++){
			if(!(s&(1<<(i-1)))){
				int tmi=LLONG_MAX;
				for(int j = 1; j <= n; j++){
					if(s&(1<<(j-1))){
						tmi=min(tmi, dis[i][j]);
					}
				}
//				cout<<"tmi:"<<" "<<tmi<<'\n';
				ma=max(ma, tmi);
			}else{
//				cout<<i<<'\n';
			}
		}
//		cout<<'\n'<<ma<<'\n';
		mi=min(mi, ma);
	}
	cout<<mi<<'\n';
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
	cin>>c>>_;
	while(_--){
		solve();
	}
	return 0;
} 
/*
估分：100+44+?+15 
我是GD-J04204，迷惑行为大赏能帮我看看GD-J04204的代码有没有加reutrn 0吗 
*/

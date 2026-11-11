#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c,t,n;
long long d,x[N],dis[N],res[N];
vector<int> vec[N];
bool vis[N];
long long Dijkstra(int x){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i = 1;i <= n;i ++) dis[i] = 1e18,res[i] = 0,vis[i] = false;
	dis[x] = 0;
	q.push({0,x});
	while(!q.empty()){
	    auto [w,u] = q.top();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int v : vec[u]){
		    if(dis[u] + 1 == dis[v]){
				res[v] ++;
			}
			else if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				res[v] = 1;
				if(!vis[v]) q.push({dis[v],v});
			}
			
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i ++){
		if(res[i] == 2) cnt ++;
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	for(int i = 1;i <= t;i ++){
		cin >> n >> d;
		for(int j = 1;j <= n;j ++){
			cin >> x[j];
		}
		for(int j = 1;j <= n;j ++){
			int l = j - 1,r = j + 1;
			while(l >= 1 && x[j] - x[l] <= d){
				vec[j].push_back(l);
				l --;
			}
			while(r <= n && x[r] - x[j] <= d){
				vec[j].push_back(r);
				r ++;
			}
		}
		int ans = 0;
		for(int j = 1;j <= n;j ++){
			ans += Dijkstra(j);
		}
		cout << ans / 2 << '\n';
		for(int j = 1;j <= n;j ++) vec[j].clear();
	}
	return 0;
} 

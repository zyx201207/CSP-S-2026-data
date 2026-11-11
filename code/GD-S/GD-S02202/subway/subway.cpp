#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 6e5 + 1;
const int K = 5e5 + 10;
const int inf = 0x3f3f3f3f;
typedef pair<int , int> pii;
int w[N]; 
vector<pii> vec[N];
int c , n , m , d , q;
/*
加了K表示地铁线路的点 
*/
int dis[N];
bool vis[N];
int dij(int st , int ed){
	priority_queue<pii , vector<pii> , greater<pii>> q; 
	dis[st] = 0;
	q.push({0 , st});
	while(!q.empty()){
		pii t = q.top();
		q.pop();
		int u = t.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(pii k : vec[u]){
			int v = k.first;
			int w = k.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(v == ed) return dis[v];
				q.push({dis[v] , v});
			}
		}
	}
}
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		int k;
		cin >> k;
		for(int j = 1 ; j <= k ; j ++){
			int a , t;
			cin >> a >> t;
			vec[K + i].push_back({a , t});
			vec[a].push_back({K + i , t});
		}
	}
//	for(int i = 1 ; i <= m ; i ++){
//		for(pii t : vec[i]){
//			int u = t.first;
//			int w = t.second;
//			if(u > K){
//				cout << i << " " << "*" << u - K;
//			}else{
//				cout << i << " " << u;
//			}
//			cout << " " << w << '\n';
//		}
//	}
	while(q --){
		int a , b;
		cin >> a >> b;
		memset(vis , 0 , sizeof(vis));
		memset(dis , inf , sizeof(dis));
		cout << w[a] + w[b] + dij(a , b) << '\n';
	}
	return 0;
}

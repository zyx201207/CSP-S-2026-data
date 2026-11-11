#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5+10 , Inf = 0x7f7f7f7f;
int n , m , d , q , c; 
int a[N];
pair<int , int> b[N];
int head[N] , nxt[N] , to[N] , cnt;
int f[N] , pos[N];
struct Node{
	int dis , w; 
	inline bool operator < (const Node x) const{
		return w > x.w;
	}
};
priority_queue<Node> heap;

inline void add(int x , int y , int z){
	to[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	pos[cnt] = z;
} 

inline void Dijkstra(int s , int t){
	for(int i = 1 ; i <= m ; i++) f[i] = Inf;
	while(!heap.empty()) heap.pop();
	f[s] = 0;
	heap.push((Node){s , 0});
	while(!heap.empty()){
		int x = heap.top().dis;
		if(heap.top().w != f[x]){
			heap.pop();
			continue;
		}
		heap.pop();
		for(int i = head[x] ; i ; i = nxt[i]){
			int y = to[i];
			if(f[y] > f[x] + pos[i]){
				f[y] = f[x] + pos[i];
				heap.push((Node){y , f[y]});
			}
		}
	}
	cout << f[t] + a[s] + a[t] << "\n";
}


signed main (){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++){
		int k; cin >> k;
		for(int j = 1 ; j <= k ; j++){
			cin >> b[j].fi >> b[j].se;
		}
		for(int q = 1 ; q <= k ; q++){
			for(int j = q+1 ; j <= k ; j++){
				add(b[q].fi , b[j].fi , b[q].se+b[j].se);
				add(b[j].fi , b[q].fi , b[q].se+b[j].se);
			}
		}
	}
	
	while(q--){
		int s , t; cin >> s >> t;
		Dijkstra(s , t);
	}
	
	return 0;
} 

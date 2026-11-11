#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n , d;
ll pos[2000005];
ll dist[2000005];
ll pass[2000005];
ll mark[5005][5005];

inline void dijkstra(int root){
	priority_queue<pair<ll , pair<ll , ll> > , vector< pair<ll , pair<ll , ll> > > , greater< pair<ll , pair<ll , ll> > > > heap;
	memset(dist , 0x3f , sizeof(dist));
	memset(pass , 0x3f , sizeof(pass));
	heap.push(make_pair(0 , make_pair(root , 0)));
	dist[root] = 0;
	pass[root] = 0;
	
	while(!heap.empty()){
		auto top = heap.top(); heap.pop();
		for(int i = top.second.first + 1;i <= n;i++){
			int len = abs(pos[top.second.first] - pos[i]);
			int edge = top.second.second + 1;
			if(len <= d){
				if(dist[i] == dist[top.second.first] + len && pass[i] == edge) mark[root][i]++;
				else if(dist[i] > dist[top.second.first] + len || pass[i] > edge){
					dist[i] = dist[top.second.first] + len;
					pass[i] = edge;
					mark[root][i] = 1;
					heap.push(make_pair(dist[i] , make_pair(i , pass[i])));
				}
			}
		}
	}
}

int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c , t; cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> pos[i];
		
		for(int i = 1;i <= n;i++) dijkstra(i);
		
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans += (mark[i][j] == 2);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;
struct Edge{
	int p;
	Long d;
};

const int N = 500;
const int M = 500000;
const int LIM = 20;
const Long INF = 0x3f3f3f3f3f3f3f3f;
const Long MOD = 998244353; 

int c, m, n, lim, q;
Long w[M];
vector<Edge> lines[N+M+1];

namespace Dijkstra{
	typedef pair<Long, int> Point;
	priority_queue<Point, vector<Point>, greater<Point>> q;
	Long dis[N+M+1];
	
	inline void run(int pioneer){
		fill(dis+1, dis+1+n+m, INF);
		q.push({dis[pioneer] = 0, pioneer});
		
		while(!q.empty()){
			Point data = q.top(); q.pop();
			int a = data.second; Long dispa = data.first;
			if(dispa > dis[a]) continue;
			
			for(Edge edge: lines[a]){
				int b = edge.p;
				Long disab = edge.d;
				Long dispab = dispa + disab;
				Long& dispb = dis[b];
				if(dispab < dispb){
					dispb = dispab;
					q.push({dispab, b});
				}
			}
		}
	}
}

inline void solve(){
	cin >> c >> n >> m >> lim >> q;
	
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	
	for(int i = m+1; i <= m+n; ++i){
		int k; cin >> k;
		lines[i].resize(k);
		while(k--){
			cin >> lines[i][k].p >> lines[i][k].d;
			lines[lines[i][k].p].push_back({i, lines[i][k].d});
		}
	}
	while(q--){
		int l, r; cin >> l >> r;
		Dijkstra::run(l);
		cout << Dijkstra::dis[r] + w[l] + w[r] << '\n';
	} 
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

//	int t; cin >> t; while(t--)
	{
		solve();
	}

	return 0;
}

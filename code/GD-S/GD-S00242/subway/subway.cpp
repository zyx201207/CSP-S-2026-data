#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
int k[505];
vector<int> a[505];
vector<int> t[505];
struct node{
	long long u, v, w;
};
struct pri{
	long long id, dist;
	bool operator < (const pri &nd) const{
		return dist > nd.dist;
	}
};
// for 1 <= c <= 8
bool vis1[80005];
long long dis1[80005];
vector<node> adj1[80005];
//

// for 12 <= c <= 19
vector<long long> sta_sub2[500005];
vector<node> adj2[505];
bool vis2[80005];
long long dis2[505][505];
//
void dijkstra1(long long st){
	priority_queue<pri> q;
	for(long long i = 1; i <= (n + 1) * m; i++){
		dis1[i] = 1e9;
		vis1[i] = false;
	}
	dis1[st] = 0;
	q.push({st, 0});

	while(!q.empty()){
		long long u = q.top().id;
		q.pop();

		if(vis1[u] == true){
			continue;
		}
		vis1[u] = true;

		for(long long i = 0; i < adj1[u].size(); i++){
			long long v = adj1[u][i].v;
			if(dis1[u] + adj1[u][i].w < dis1[v]){
				dis1[v] = dis1[u] + adj1[u][i].w;
				q.push({v, dis1[v]});
			}
		}
	}
}
void dijkstra2(long long st){
	priority_queue<pri> q;
	for(long long i = 1; i <= n; i++){
		dis2[st][i] = 1e9;
		vis2[i] = false;
	}
	dis2[st][st] = 0;
	q.push({st, 0});

	while(!q.empty()){
		long long u = q.top().id;
		q.pop();

		if(vis2[u] == true){
			continue;
		}
		vis2[u] = true;

		for(long long i = 0; i < adj2[u].size(); i++){
			long long v = adj2[u][i].v;
			if(dis2[st][u] + adj2[u][i].w < dis2[st][v]){
				dis2[st][v] = dis2[st][u] + adj2[u][i].w;
				q.push({v, dis2[st][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(long long i = 1; i <= n; i++){
		cin >> k[i];
		a[i].push_back(-1);
		t[i].push_back(-1);
		for(long long j = 1; j <= k[i]; j++){
			long long aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}

	if((c == 0 && n <= 50 && m <= 300 && q <= 200) || (c >= 1 && c <= 8)){
		for(long long i = 1; i <= n; i++){
			for(long long j = 1; j <= k[i]; j++){
				long long noww = i * m + a[i][j];
				if(j != k[i]){
					long long nxt = i * m + a[i][j + 1];
					adj1[noww].push_back({noww, nxt, 0});
					adj1[nxt].push_back({nxt, noww, 0});
				}
				adj1[noww].push_back({noww, a[i][j], t[i][j]});
				adj1[a[i][j]].push_back({a[i][j], noww, t[i][j]});
			}
		}

		// for(long long i = 1; i <= (n + 1) * m; i++){
		// 	cout << i << ": ";
		// 	for(long long j = 0; j < adj1[i].size(); j++){
		// 		cout << adj1[i][j].v << " ";
		// 	}
		// 	cout << "\n";
		// }

		while(q--){
			long long st, ed;
			cin >> st >> ed;
			dijkstra1(st);
			cout << w[st] + w[ed] + dis1[ed] << "\n";
		}
	}
	if(c >= 12 && c <= 19){
		for(long long i = 1; i <= n; i++){
			for(long long j = 1; j <= k[i]; j++){
				sta_sub2[a[i][j]].push_back(i);
			}
		}
		for(long long i = 1; i <= m; i++){
			for(long long j1 = 0; j1 < sta_sub2[i].size(); j1++){
				for(long long j2 = j1 + 1; j2 < sta_sub2[i].size(); j2++){
					adj2[sta_sub2[i][j1]].push_back({sta_sub2[i][j1], sta_sub2[i][j2], 1});
					adj2[sta_sub2[i][j2]].push_back({sta_sub2[i][j2], sta_sub2[i][j1], 1});
					// cout << sta_sub2[i][j1] << " " << sta_sub2[i][j2] << "\n";
				}
			}
		}

		// for(long long i = 1; i <= n; i++){
		// 	cout << i << ": ";
		// 	for(long long j = 0; j < adj2[i].size(); j++){
		// 		cout << adj2[i][j].v << " ";
		// 	}
		// 	cout << "\n";
		// }

		for(long long i = 1; i <= n; i++){
			dijkstra2(i);
		}

		while(q--){
			long long st, ed;
			cin >> st >> ed;
			long long ans = 1e9;

			for(long long i = 0; i < sta_sub2[st].size(); i++){
				for(long long j = 0; j < sta_sub2[ed].size(); j++){
					ans = min(ans, dis2[sta_sub2[st][i]][sta_sub2[ed][j]]);
				}
			}

			cout << w[st] + w[ed] + ans * 2 * t[1][1] + 2 * t[1][1] << "\n";
		}
	}
	// if(c >= 7 && c <= 11){

	// }
	

	return 0;
}

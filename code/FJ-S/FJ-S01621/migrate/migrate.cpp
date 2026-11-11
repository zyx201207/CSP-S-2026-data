#include<bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const int N = 310;
const int inf = 0x3f3f3f3f;

int c, t;
int n;
ll d;
ll x[N];

ll dis[N][N];
ll cnt[N][N];


ll read(){
	ll x = 0, flag = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * flag;
}

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue ;
				if(dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = 0;
				}
				if(dis[i][k] + dis[k][j] == dis[i][j]){
					cnt[i][j] += cnt[i][k] * cnt[k][j];
				}
			}
		}
	}
	return ;
}

//struct node{
//	int u;
//	int dist;
//	bool operator <(const node &other) const{
//		return dist > other.dist;
//	}
//};

//vector<int> edge[2000010];
//int disst[2000010];
//void dij(int s){
//	for(int i = 1; i <= n; i++) disst[i] = inf;
//	disst[s] = 0;
//	priority_queue<node> pq;
//	pq.push({s, disst[s]});
//	while(!pq.empty()){
//		node cur = pq.top(); pq.pop();
//		int u = cur.u;
//		if(cur.dist > disst[u]) continue ;
//		for(auto v : edge[u]){
//			if(disst[u] + 1 < disst[v])
//		}
//	}
//}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	if(c >= 0 && c <= 6){
		while(t--){
			memset(dis, inf, sizeof(dis));
			memset(cnt, 0, sizeof(cnt));
			memset(x, 0, sizeof(x));
			cin >> n >> d;
			for(int i = 1; i <= n; i++) x[i] = read();
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j) continue ;
					if(abs(x[j] - x[i]) <= d){
						dis[i][j] = 1;
						cnt[i][j]++;
					}
				}
			}
			
			floyd();
			
			int ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					if(cnt[i][j] == 2){
						ans++;
					}
				}
			}
			cout << ans << '\n';
			
//			for(int i = 1; i <= n; i ++){
//				for(int j = i + 1; j <= n; j++){
//					cout << dis[i][j] << " ";
//				}cout << endl;
//			}
		}
	}
	
//	if(c >= 11 && c <= 12){
//		while(t--){
//			cin >> n >> d;
//			for(int i = 1; i <= n; i++) cin >> x[i];
//			for(int i = 1; i <= n; i++){
//				for(int j = 1; j <= n; j++){
//					if(i == j) continue ;
//					if(abs(x[j] - x[i]) <= d){
//						edge[i].push_back(j);
//					}
//				}
//			}
//			
//			dij(1);
//		}
//	}
	return 0;
}

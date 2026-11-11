#include <bits/stdc++.h>
#define int long long
using namespace std;
bool Mbe;
const int M = 1e6+34;
int c,n,m,d,q;
int w[M];
//int a[505][M],t[505][M];



struct node{
	int nx,w;
	friend bool operator< (node a, node b){
		return a.w > b.w;
	}
};
vector<node> v[1005];
int dist[M],vis[M];
priority_queue<node> pq;
void dijstra(int st, int ed){
	for( int i = 1; i <= 1005;i++) dist[i] = 1e18,vis[i]=0;
	dist[st]=0;
	while (!pq.empty()) pq.pop();
	
	pq.push({st,0});
	while (!pq.empty()){
		
		auto cur = pq.top(); pq.pop();
		if (vis[cur.nx]) continue;
		vis[cur.nx]=1;
//		cout << cur.nx << '\n';
		for (auto u : v[cur.nx]){
			int nx = u.nx;
//			cout << cur.nx << ' ' << nx << '\n';
			int w =u.w;
			if (dist[nx] > dist[cur.nx] + w){
				dist[nx] = dist[cur.nx] + w;
				pq.push({nx,dist[nx]}); 
			}
		}
	}
}

/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3

1 2


*/

bool Med;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
//	cerr << "Mem: " << (&Mbe - &Med) / 1048576.0 << '\n';
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m;i++) cin >> w[i];
	for (int i = 1; i <= n;i++){
		int k; cin >> k;
		for (int j = 1; j <=k;j++){
			int nx,w;
			cin >> nx >> w;
//			cin >> a[i][j];
//			cin >> t[i][j];
			
			v[i+500].push_back({nx,w});
			v[nx].push_back({i+500,w});
			
		}
		
	}
	
	for (int r = 1; r <= q;r++){
//		cin >> X[r] >> Y[r];
		int ans =0;
		int x,y; cin >> x >> y;
		ans = w[x] +w[y]; // x口入站 + y口出站 -> 固定时间 
		dijstra(x,y);
		ans += dist[y];
		cout<<ans << '\n';
		
	}
	
	cerr << "Time: " << (double)(clock() *1.0 / CLOCKS_PER_SEC) <<'\n';
	return 0;
}

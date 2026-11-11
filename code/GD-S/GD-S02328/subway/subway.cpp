#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 505, M = 5e5+5, Q = 1e5+5;
struct Nod{int y, w;};
struct Qry{;int x, y, id;} qry[Q]; 
int c, n, m, d, q, k[N], w[M], dis[M+N], ans[Q];
vector<Nod> to[M+N];
bool cmp(Qry a, Qry b){return a.x < b.x;}
int solve(int s, int t){
	priority_queue<pii, vector<pii>, greater<pii>> q;
	memset(dis, 0x3f, sizeof(dis));
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty()){
		int x = q.top().second, d = q.top().first;
		q.pop();
		if(dis[x] < d) continue;
		for(auto i:to[x]){
			int y = i.y, val = i.w;
			if(dis[x]+val < dis[y]){
				dis[y] =dis[x]+val;
				q.push({dis[y], y});
			}
		}
	}
	return dis[t]+w[s]+w[t];
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1,a,t; j <= k[i]; j++){
			cin >> a >> t;
			to[a].push_back({m+i, t});
			to[m+i].push_back({a, t});
		}
	}
	for(int i = 1,x,y; i <= q; i++){
		cin >> x >> y;
		qry[i].x = min(x, y), qry[i].y = max(x, y);
		qry[i].id = i;
	}
	sort(qry+1, qry+q+1, cmp);
	for(int i = 1; i <= q; i++){
		int x = qry[i].x, y = qry[i].y, id = qry[i].id;
		if(x == qry[i-1].x) ans[id] = dis[y]+w[x]+w[y];
		else ans[id] = solve(x, y);
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
	return 0;
}

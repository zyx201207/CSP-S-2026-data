#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int MIN_M = 1e4 + 5;
const int M = 5e4 + 5;
int c, n, m, d, T, k, x, y, a;
int w[M], t[N][M], in[MIN_M];
int in_tot[MIN_M];
int minr[MIN_M][MIN_M];
bool vis[MIN_M];
bool flagA = 1, flagB = 1;
vector <pair <int, int> > roads[MIN_M];
vector <int> kskbl[N];
vector <int> road[MIN_M];
int calc(int x, int y, int z){
	return (t[x][y] + t[y][z]);
}
queue <pair <int, int> > q;
void init(int st, int l, int tim){
	for(int f : road[l]){
		minr[st][f] = minr[f][st] = min({minr[f][st], minr[st][f], tim});
		in_tot[f]--;
		if(!in_tot[f] || tim == 0) vis[f] = 1;
		q.push({f, l});
	}
}
void bfs(int st){
	memset(vis, 0, sizeof(vis));
	for(int i = 0;i < kskbl[st].size();i++) init(st, kskbl[st][i], t[st][kskbl[st][i]]);
	for(int i = 1;i <= m;i++) in_tot[i] = in[i];
	while(!q.empty()){
		pair <int, int> u = q.front(); q.pop();
		int u1 = u.first, u2 = u.second;
		for(pair <int, int> f : roads[u1]){
			if(vis[f.first]) continue;
			if(f.second != u2){
				int tim = calc(u2, f.first, f.second);
				if(tim > minr[st][f.first]) continue;
				init(st, f.first, tim);
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> T;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k;
		if(k > 2) flagA = 0;
		for(int j = 1;j <= k;j++){
			cin >> a >> t[i][j];
			for(int l : road[i]) roads[l].push_back({a, l});
			road[i].push_back(a);
			kskbl[a].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++) in[i] = road[i].size();
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			if(i == j) continue;
			minr[i][j] = 1145141919810;
		}
	}
	for(int i = 1;i <= n;i++) bfs(i);
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++) cout << minr[i][j] << " ";
		cout << "\n";
	}
	while(T--){
		cin >> x >> y;
		cout << minr[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
using LL = long long;

struct node{
	int v, t;
};

int x, y, c, n, m, d, q, w[N], k[N], a[501][50001], t[501][50001];
LL ans;
bool vis[N];
vector<int> vt[N];

void bfs(int s){
	queue<node> q;
	q.push({s, w[s]});
	vis[s] = 1;
	
	while(!q.empty()){
		int u = q.front().v;
		int now = q.front().t;
		q.pop();
		
		if(u == y){
			cout << now + w[y] << "\n";
			return ;
		}
		
		for(int i : vt[u]){
			int ppp = 0;
			
			for(int j = 1; j <= k[i]; ++j){
				if(vis[a[i][j]]) continue;
				if(a[i][j] == u){
					ppp = t[i][j];
					continue;
				}
				
				vis[a[i][j]] = 1;
				q.push({a[i][j], now + t[i][j] + ppp});	
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		
		for(int j = 1; j <= k[i]; ++j){
			cin >> a[i][j] >> t[i][j];
			
			vt[j].push_back(i);
		}
	}
	for(int i = 1; i <= q; ++i){
		cin >> x >> y;
		memset(vis, 0, sizeof(vis));
		
		bfs(x);
	}
	return 0;
}

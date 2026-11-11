#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define OK cerr << "OK" << endl;

using namespace std;

const int maxn = 510, maxm = 5e5 + 10;

ll w[maxm];

ll G[maxn][maxn], min_t[maxn][maxn];

struct sub{
	int id;
	ll time;
};

vector<sub> s[maxn], m_adj[maxm];


//void dj(){
//	
//} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k, a, ti, x, y;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> k;
		while(k--){
			cin >> a >> ti;
			m_adj[a].push_back({i, ti});
			s[i].push_back({a, ti});
		}
	}
	
	
	int x_id, y_id;
	for(int i = 1; i <= m; ++i){
		for(sub x : m_adj[i]){
			for(sub y : m_adj[i]){
				x_id = x.id;
				y_id = y.id;
				if((!G[x_id][y_id] || G[x_id][y_id] > x.time + y.time) && x_id != y_id){
					G[x_id][y_id] = x.time + y.time;
				}
			}
		}
	}
	
//	for(int i = 1; i <= n; ++i){
//		for(int j = 1; j <= n; ++j){
//			cerr << G[i][j] << " ";
//		}
//		cerr << endl;
//	}
	
	
	ll min_x;
	
	memset(min_t, 0x7f, sizeof(min_t));
//	priority_queue<pair<int, int> > pq;
	for(int i = 1; i <= n; ++i){
//		pq.push({0, i});
//		int j, val;
		bool fl[maxn] = {};
		min_t[i][i] = 0;
		for(int j = 1; j <= n; ++j){
			min_x = 0;
			for(int o = 1; o <= n; ++o){
				if(min_t[i][min_x] > min_t[i][o] && !fl[o]){
					min_x = o;
					
//	OK;debug(min_x);debug(o);
	
				}
			}
			fl[min_x] = 1; 
			if(min_x == 0){
				continue;
			}
			for(int o = 1; o <= n; ++o){
				if(fl[o]){
					continue;
				}
				if(G[min_x][o] && G[min_x][o] + min_t[i][min_x] < min_t[i][o]){
				
//					debug(o);
////				debug(min_x);
				
					min_t[i][o] = G[min_x][o] + min_t[i][min_x];
					
//					debug(min_t[i][o]);
				}
			}
			
//			cout << "i = " << i << endl;
//			for(int e = 1; e <= n; ++e){
//				cout << e << " " << " ";
//			}
//			cout << endl;
		}
//		while(!pq.empty()){
//			j = pq.top().second;
//			val = pq.top().first;
//			pq.pop();
//			if(min_t[i][j] > val){
//				min_t[i][j] = val;
//				for(int o = 1, o <= )
//			} 
//		}
	}
	
//	for(int i = 1; i <= n; ++i){
//		for(int j = 1; j <= n; ++j){
//			cerr << min_t[i][j] << " ";
//		}
//		cerr << endl;
//	}
	
	ll ans;
	while(q--){
		ans = 0x7f7f7f7f7f7f7f7f;
		cin >> x >> y;
		for(sub a : m_adj[x]){
			for(sub b : m_adj[y]){
				
//				debug(a.id);
//				debug(b.id);
//				debug(a.time);
//				debug(b.time);
//				debug(min_t[a.id][b.id]);
				
				ans = min(ans, min_t[a.id][b.id] + a.time + b.time);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
}


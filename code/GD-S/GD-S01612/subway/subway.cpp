#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
const int INF = 4e18;
int c, n, m, d, q, cnt, sm;
int w[N], vis[N];
int dis[5002][5002];
struct node{
	int to, val;
};
vector<node> g[N];

struct cx{
	int idx, val;
	friend bool operator < (cx a, cx b){
		return a.val > b.val;
	}
};
priority_queue<cx> pq;
void dijk(int st){
	while(!pq.empty()) pq.pop();
	for(int i = 1;i <= cnt;i++) vis[i] = 0;
	vis[st] = 1; pq.push((cx){st, 0});
	dis[st][st] = 0;
	while(!pq.empty()){
		cx sta = pq.top(); pq.pop();
		int pos = sta.idx; vis[pos] = 1;
		for(int i = 0;i < g[pos].size();i++){
			int nxt = g[pos][i].to, v = g[pos][i].val;
			if(dis[st][nxt] > dis[st][pos] + v){
				dis[st][nxt] = dis[st][pos] + v;
				if(!vis[nxt]) pq.push((cx){nxt, dis[st][nxt]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	cnt = m;
	for(int i = 1;i <= n;i++){
		int k; cin >> k;
		cnt++; sm += k;
		for(int j = 1;j <= k;j++){
			int pos, t; cin >> pos >> t;
			g[pos].push_back((node){cnt, t});
			g[cnt].push_back((node){pos, t});
		}
	}
	if(sm <= 5000){
		for(int i = 1;i <= cnt;i++){
			for(int j = 1;j <= cnt;j++){
				dis[i][j] = INF;
			}
		} 
		for(int i = 1;i <= m;i++){
			dijk(i);
		}
		for(int i = 1;i <= q;i++){
			int fst, scd; cin >> fst >> scd;
			cout << dis[fst][scd] + w[fst] + w[scd] << endl;
		}
	}
	else{
		for(int i = 1;i <= q;i++){
			int fst, scd; cin >> fst >> scd;
		}
	}
	return 0;
}

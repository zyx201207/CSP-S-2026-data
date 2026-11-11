#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 5e5 + 500 + 10;
int c, m, n, d, Q;
ll w[MAX], dis[MAX], ans[MAX];

struct node{
	int v, w;
	bool operator < (const node &tmp) const {
		return w > tmp.w;
	}
};

struct qu{
	int id, s, t;
}query[MAX];

bool cmp_s(qu x, qu y){
	return x.s < y.s;
}

vector<node> e[MAX];
bool done[MAX];
priority_queue<node> q;

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> m >> n >> d >> Q;
	for(int i = 1; i <= n; ++i) cin >> w[i];
	for(int i = 1, k; i <= m; ++i){
		cin >> k;
		for(int j = 1, v, w; j <= k; ++j){
			cin >> v >> w;
			e[n + i].push_back({v, w});
			e[v].push_back({n + i, w});
		}
	}
	for(int i = 1, s, t; i <= Q; ++i){
		cin >> s >> t;
		if(s > t) swap(s, t);
		query[i] = {i, s, t};
	}
	sort(query + 1, query + Q + 1, cmp_s);
	for(int i = 1; i <= Q; ++i){
		if(i == 1 || query[i].s != query[i - 1].s){
			while(!q.empty()) q.pop();
			q.push({query[i].s, 0});
			memset(done, 0, sizeof(done));
			memset(dis, 0x3f3f3f, sizeof(dis));
			dis[query[i].s] = 0;
			while(!q.empty()){
				int v = q.top().v;
				int w = q.top().w;
				q.pop();
				done[v] = 1;
				for(int i = 0; i < e[v].size(); ++i){
					if(dis[e[v][i].v] > dis[v] + e[v][i].w){
						dis[e[v][i].v] = dis[v] + e[v][i].w;
					}
					if(!done[e[v][i].v]) q.push({e[v][i].v, e[v][i].w});
				}
			}
		}
		ans[query[i].id] = w[query[i].s] + w[query[i].t] + dis[query[i].t];
	}
	for(int i = 1; i <= Q; ++i) cout << ans[i] << '\n';
	return 0;
}

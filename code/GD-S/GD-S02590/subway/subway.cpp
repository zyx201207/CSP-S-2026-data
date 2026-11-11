#include<bits/stdc++.h>
#define pb push_back
using namespace std;
/*

*/
typedef long long ll;
const int N = 505, M = 5e5 + 5;
inline ll read(){
	ll xx = 0;char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while('0' <= c && c <= '9'){
		xx = (xx<<1) + (xx<<3) + (c^48);
		c = getchar();
	}
	return xx;
}
//inline void wt(ll xx){
//	if(xx > 9){
//		wt(xx / 10);
//	}
//	putchar((xx%10)^48);
//	return ;
//}
int cc, n, m, d, qq, tp;
ll w[M];
int head[N + M + 5], nxt[M << 1], to[M << 1];//双向 
ll val[M << 1];
ll dis[N + M + 5];
bool vis[N + M + 5];
//vector<int> vec[M];
vector<int> tr[M];
struct NODE{
	int id;
	ll d;
	vector<int> v;
	inline bool operator<(const NODE& no)const{
		return d > no.d;
	}
};
priority_queue<NODE> q;
inline void add(int a, int b, ll vl){
	nxt[++tp] = head[a];
	to[tp] = b;
	val[tp] = vl;
	head[a] = tp;
	return ;
}
void dij(int st){
	NODE tep;
	tep.id = st;
	tep.d = 0;
	tep.v.clear();
	tep.v.pb(st);
	q.push(tep);
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0;
	int id;
	ll d;
	NODE ft;
	while(!q.empty()){
		ft = q.top();
		q.pop();
		if(vis[ft.id]){
			continue;
		}
		id = ft.id;
		d = ft.d;
		vis[id] = true;
		if(id <= m){
			tr[id] = ft.v;
		}
//		printf("id : %d\n", id);
		for(int i = head[id], t; i; i = nxt[i]){
			t = to[i];
			if(dis[t] > d + val[i]){
				dis[t] = d + val[i];
				if(!vis[t]){
					tep = ft;
					tep.id = t;
					tep.d = dis[t];
//					if(t <= m){
						tep.v.pb(t);
//					}
					q.push(tep);
				}
			}
		}
	}
	return ;
}
//inline bool chk(int a, int b){//if A in B`s shortest_pass
//	auto p = lower_bound(vec[b].begin(), vec[b].end(), a);
//	return (p != vec[b].end());
//}
inline int get_lca(int a, int b){
	int l = 0, r = min(tr[a].size(), tr[b].size()) - 1, mid;
	while(l < r){
		mid = ((l + r + 1) >> 1);
		if(tr[a][mid] == tr[b][mid]){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return tr[a][l];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> cc >> n >> m >> d >> qq;
	cc = read();
	n = read();
	m = read();
	d = read();
	qq = read();
	for(int i = 1; i <= m; ++i){
//		cin >> w[i];
		w[i] = read();
	}
	ll num;
	int tot = m;
	for(int i = 1, k, a; i <= n; ++i){
//		cin >> k;
		k = read();
		++tot;//路线站台虚拟编号 
		for(int j = 1; j <= k; ++j){
//			cin >> a >> num;
			a = read();
			num = read();
			add(a, tot, num);
			add(tot, a, num);
			//双向边 
		}
	}
	//全源最短路 
	dij(1);
//	for(int i = 1; i <= tot; ++i){
//		printf("%lld ", dis[i]);
//	}
	//
	for(int i = 1, st, en, lca; i <= qq; ++i){
//		cin >> st >> en;
		st = read();
		en = read();
		lca = get_lca(st, en);
		printf("%lld\n", dis[st] + dis[en] - 2 * dis[lca] + w[st] + w[en]);
//		wt(dis[st] + dis[en] - 2 * dis[lca] + w[st] + w[en]);
//		putchar('\n');
		//不存在同时成立，否则st==en 
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 3
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
2 5

*/

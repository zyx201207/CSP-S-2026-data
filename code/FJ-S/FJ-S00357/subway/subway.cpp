#include <bits/stdc++.h>
#define pii pair <int, int>
#define fi first
#define se second
#define pub push_back
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5, MAX = 4e4 + 5, D = 25, inf = 1e18; //MAX是部分分的最大点数 
int c, n, m, d, Q, tot, a[M]; //tot为总点数 
int dis[MAX]; bool vis[MAX];
struct node{ int to, w; };
bool operator < (const node &t1, const node &t2){ return t1.w > t2.w; }
vector <node> ed[MAX]; vector <int> jl[M]; 
vector <node> ed2[N]; vector <int> xl[M]; int cd[N][N], xt; // 适用于12~19的测试点 
map <pii, int> mp; vector <pii> v;
priority_queue <node> q;
void dij(int s){
	for(int i = 1;i <= tot;i++) dis[i] = inf, vis[i] = 0;
	dis[s] = 0, q.push({s, 0});
	while(!q.empty()){
		int now = q.top().to; q.pop();
		if(vis[now]) continue; vis[now] = 1;
		for(auto bl : ed[now]){
			int i = bl.to, bw = bl.w;
			if(i < s) continue;
			if(dis[now] + bw < dis[i])
				dis[i] = dis[now] + bw, q.push({i, dis[i]});
		}
	}
	for(int i = 1;i <= tot;i++){
		if(mp.find({s, i}) != mp.end()) mp[{s, i}] = dis[i] + a[s] + a[i];
	}
}
void dij2(int s){
	for(int i = 1;i <= n;i++) dis[i] = inf, vis[i] = 0;
	dis[s] = 0, q.push({s, 0});
	while(!q.empty()){
		int now = q.top().to; q.pop();
		if(vis[now]) continue; vis[now] = 1;
		for(auto bl : ed2[now]){
			int i = bl.to, bw = bl.w;
			if(i < s) continue;
			if(dis[now] + bw < dis[i])
				dis[i] = dis[now] + bw, q.push({i, dis[i]});
		}
	}
	for(int i = 1;i <= n;i++) cd[s][i] = dis[i];
}
signed main(){
//	freopen("subway3.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	tot = m;
	for(int i = 1;i <= n;i++){
		int x, lst = -1; cin >> x;
		while(x--){
			int y, k; cin >> y >> k; tot++;
			if(!(c >= 12 && c <= 19)){
				ed[y].pub({tot, k}), ed[tot].pub({y, k});
				if(lst != -1) ed[lst].pub({tot, 0}), ed[tot].pub({lst, 0});
				lst = tot;
			} else{
				xl[y].pub(i); xt = k;
			}
		}
	}
	for(int i = 1;i <= Q;i++){
		int x, y; cin >> x >> y; if(x > y) swap(x, y);
		v.pub({x, y}); mp[{x, y}] = -1;
	}
	if(c >= 12 && c <= 19){
		for(int i = 1;i <= m;i++){
			int lst = -1;
			for(auto j : xl[i]){
				if(lst != -1) ed2[j].pub({lst, 1}), ed2[lst].pub({j, 1});
				lst = j;
			}
		}
		for(int i = 1;i <= n;i++) dij2(i);
		for(auto i : v){
			int s = i.fi, t = i.se, tmp = inf;
			bool pd = 0;
			for(auto t1 : xl[s]){
				for(auto t2 : xl[t]){
					if(t1 == t2){ tmp = a[s] + a[t] + 1ll * xt * 2; pd = 1; break; }
					tmp = min(tmp, 1ll * (a[s] + a[t]) + 1ll * xt * 2 + 1ll * cd[t1][t2] * xt * 2);
				}
				if(pd) break;
			}
			cout << tmp << "\n";
		}
		return 0;
	}
	for(int i = 1;i <= m;i++) dij(i);
	for(auto i : v){
		cout << mp[i] << "\n";
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

12 3 7 20 1
1 2 3 4 5 6 7
3 1 3 2 3 3 3
4 3 3 4 3 5 3 6 3
2 6 3 7 3
1 3
18:20写完76分（预估） 
*/

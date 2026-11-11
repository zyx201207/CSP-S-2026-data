#include<bits/stdc++.h>
#define endl '\n'
#define debug() cout << "qwq" << endl;
#define int long long
#define pii pair<int, int> 
#define mp make_pair
using namespace std;

const int M = 5e5 + 10, N = 510;
int c, n, m, d, q, maxn; 
int w[M];
int eg[1010][1010];
int f[510][510];
int dis[M];
bool vis[1010];

void test_1_to_8(int s){
	for(int i = 1; i <= m + n; i ++) dis[i] = 1e18;
	memset(vis, false, sizeof vis);
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(mp(0, s));
	while(!q.empty()){
		pii nw = q.top(); q.pop();
		int u = nw.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = 1; i <= n + m; i ++){
			int v = i;
			int w = eg[u][v];
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push(mp(dis[v], v));
			}
		}
	}
}

void test_9_to_11(int s){
	for(int i = 1; i <= maxn; i ++) f[s][i] = 1e18;
	memset(vis, false, sizeof vis);
	f[s][s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(mp(0, s));
	while(!q.empty()){
		pii nw = q.top(); q.pop();
		int u = nw.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = 1; i <= maxn; i ++){
			int v = i;
			int w = eg[u][v];
			if(f[s][u] + w < f[s][v]){
				f[s][v] = f[s][u] + w;
				q.push(mp(f[s][v], v));
			}
		}
	}
}

const int MAXN = 1e6 + 10;
struct node{
	int v, nxt;
}e[MAXN << 1];
int hd[MAXN], cnt;
void add(int u, int v){
	cnt ++;
	e[cnt] = {v, hd[u]};
	hd[u] = cnt;
}

int bfs(int st, int tar){
	queue<pii> q;
	q.push(mp(st, 0));
	memset(vis, false, sizeof vis);
	while(!q.empty()){
		pii nw = q.front();
		q.pop();
		//cout << nw.first << " " << nw.second << endl;
		if(nw.first == tar) return nw.second;
		vis[nw.first] = true; 
		for(int i = hd[nw.first]; i; i = e[i].nxt){
			int to = e[i].v;
			if(vis[to]) continue;
			q.push(mp(to, nw.second + 1));
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	if(c <= 8){
		//可以跑q次dijsktra
		memset(eg, 0x3f, sizeof eg);
		int t, x, y;
		for(int i = 1; i <= n; i ++){
			cin >> t;
			for(int j = 1; j <= t; j ++){
				cin >> x >> y;
				eg[m + i][x] = eg[x][m + i] = min(eg[m + i][x], y);
			}
		}
		for(int i = 1; i <= q; i ++){
			cin >> x >> y;
			test_1_to_8(x);
			cout << w[x] + dis[y] + w[y] << endl;
		}
	}else if(c >= 9 && c <= 11){
		//可以跑m次dijsktra，跑出来全源最短路 
		memset(eg, 0x3f, sizeof eg);
		int t, x = 0, y, xx = 0, yy;
		for(int i = 1; i <= n; i ++){
			cin >> t;
			if(t == 1) cin >> x >> y;
			else{
				cin >> x >> y >> xx >> yy;
				eg[x][xx] = eg[xx][x] = min(eg[x][xx], y + yy);
			}
			maxn = max(maxn, max(x, xx));
		}
		for(int i = 1; i <= maxn; i ++){
			test_9_to_11(i);
		}
		for(int i = 1; i <= q; i ++){
			cin >> x >> y;
			cout << w[x] + w[y] + f[x][y] << endl;
		}
	}else if(c >= 12 && c <= 19){
		int t, x, y;
		for(int i = 1; i <= n; i ++){
			cin >> t;
			for(int j = 1; j <= t; j ++){
				cin >> x >> y;
				add(m + i, x);
				add(x, m + i);
			}
		}
		int z = y;
		for(int i = 1; i <= q; i ++){
			cin >> x >> y;
			cout << w[x] + w[y] + bfs(x, y) * z << endl; 
		}
	}
	
	return 0;
}
/*
15.59
电脑死机重启了。。。
不会写B怎么办 

每一条地铁线路看成一个点，每一个地铁站也看成一个点
然后，连边，则每个地铁站最多有20条边
于是可以暴力的写前8个 
16.38
写完了这一档的性质 

特殊性质A:
经过一个的显然没用 
经过两个地铁站，那么直接在这两个地铁站之间连边即可 
此时n<=500，而由于题目中保证了图联通，所以最多只有500个地铁站
如果跑Floyd，那么，复杂度是n^3,1.25e8，有点危险
如果跑m遍dijsktra?!，最多只有500条边？！ 
500 * (500 log500)
那就过了 
17.03
写完了这一档的性质，要了一张新演草纸 

特殊性质B：
也就是说，边权均为1
那么，12-15，每次询问跑一个BFS即可 
16-19等会再写。 
*/

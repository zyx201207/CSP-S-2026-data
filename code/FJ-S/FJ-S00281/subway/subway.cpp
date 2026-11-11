#include<bits/stdc++.h>
#define int long long
#define INF 1e17
using namespace std;

const int N = 5e5 + 10, M = 515;

bool b1;

int ans, res;
int n, m, d, q; //n表示线路  m表示地铁站数 
int w[N]; //进出站时间
int dis[M][M];
vector<pair<int, int> > path[N]; //表示点i经过哪些线路,且步行时间为多少 

bool b2;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + '0');
	else write(x / 10), putchar(x % 10 + '0');
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; ++i) w[i] = read();
	for(int i = 1; i <= n; ++i){
		int k = read();
		for(int j = 1; j <= k; ++j){
			int a = read(), t = read();
			path[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dis[i][j] = INF;
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < path[i].size(); ++j){
			for(int k = 0; k < path[i].size(); ++k){
				int u = path[i][j].first, v = path[i][k].first;
				int disu = path[i][j].second, disv = path[i][k].second;
				if(u == v) continue;
				dis[u][v] = min(dis[u][v], disu + disv);
			}
		}
	}
	
	//Floyd
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j){
				if(i == j || i == k || j == k) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
	
	while(q--){
		int x = read(), y = read();
		ans = w[x] + w[y], res = INF;
		
		int u, v, disu, disv;
		for(int i = 0; i < path[x].size(); ++i){
			for(int j = 0; j < path[y].size(); ++j){
				u = path[x][i].first, v = path[y][j].first;
				disu = path[x][i].second, disv = path[y][j].second;
				res = min(res, disu + disv + dis[u][v]);
			}
		}
		write(ans + res), puts("");
	}
	return 0;
}


/*
记dis[i][j]表示从i线路转到j线路的最小步行时间
枚举 入口线路S 出口线路T  O(d^2) 
答案w[x] + w[y] + t[S][] + t[T][] + dis[S][T]
复杂度O(qd^2)

怎么求dis
对于一个点k 满足k在u线路上,也在v线路上
则有dis[u][v] = min(dis[u][v], t[u][] + t[v][])
然后跑floyd
复杂度O(md^2 + n^3)
感觉很对 
但是1s跑不动？

感觉上md^2跑不满

不管了加个快写跑得飞快 
//	cout << (&b1 - &b2) / (1024.0 * 1024.0) << "MB\n";
//	system("fc subway.out subway.ans"); return 0;
*/

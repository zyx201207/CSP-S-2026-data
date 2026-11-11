#include<algorithm>
#include<cstdio>
using namespace std;
using ll = long long;
constexpr int N = 505, M = 5e5 + 5;
void chkmin(ll& x, ll y)noexcept{if(x > y)x = y;}
int head[N + M], nxt[M << 1], to[M << 1], dw[M << 1], dnt;
void add_edge(int u, int v, int w)noexcept{
	nxt[++dnt] = head[u];
	head[u] = dnt;
	to[dnt] = v, dw[dnt] = w;
}
int w[M];
ll dis[N][N];
int read()noexcept{ //这输入咋这么多啊。。。 
	char ch = getchar();
	int ret = 0;
	while(ch < '0' || '9' < ch)ch = getchar();
	while('0' <= ch && ch <= '9')ret = ret * 10 + (ch ^ 48), ch = getchar();
	return ret; 
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int n, m, q, _;
//	scanf("%*d%d%d%*d%d", &n, &m, &q);
	_ = read(), n = read(), m = read(), _ = read(), q = read();
	for(int i = 1;i <= m;i++)w[i] = read();
	for(int i = 1;i <= n;i++){
		int k = read();
		while(k--){
			int a = read(), t = read();
			add_edge(i, a + n, t), add_edge(a + n, i, t);
		}
		for(int j = i + 1;j <= n;j++)dis[i][j] = dis[j][i] = 1e18;
	}
//	puts("here");
	for(int i = 1;i <= n;i++){ // O(d \sum k_i)
		for(int d = head[i];d;d = nxt[d]){
			int u = to[d]; //地铁站编号 
			for(int _d = head[u];_d;_d = nxt[_d]){
				int v = to[_d]; // 路线编号 
				if(v != i){
					chkmin(dis[i][v], dw[d] + dw[_d]);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				chkmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			ll xd = dis[i][j] == 1e18 ? -1 : dis[i][j];
//			printf("dis[%d, %d]=%lld\n", i, j, xd); 
//		}
//	}
	for(int i = 1;i <= q;i++){
		int x = read(), y = read();
		//scanf("%d%d", &x, &y);
		ll ans = 1e18;
		for(int d = head[x + n];d;d = nxt[d]){
			int u = to[d];
			for(int _d = head[y + n];_d;_d = nxt[_d]){
				int v = to[_d];
				chkmin(ans, dis[u][v] + dw[d] + dw[_d]);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
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

*/

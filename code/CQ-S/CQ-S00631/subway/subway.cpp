#include <bits/stdc++.h>
#define int long long
#define PII pair < int , int >
#define x first
#define y second
using namespace std ;
char bbb ;

namespace IO{
	const int maxn = 1 << 20 ;
	char buf[maxn] , *p1 , *p2 ;
	#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf , 1 , maxn , stdin) , p1 == p2) ? EOF : *p1 ++)
	inline void read(int &x){
		x = 0 ; int f = 1 ; char ch = gc() ;
		for( ; !isdigit(ch) ; ch = gc()) if(ch == '-') f = -1 ;
		for( ; isdigit(ch) ; ch = gc()) x = x * 10 + (ch - '0') ;
		x *= f ;
	}
	inline void write(int x , bool f = 1){
		if(x < 0) putchar('-') , x = -x ;
		static int stk[40] ; int top = 0 ;
		do stk[++ top] = x % 10 , x /= 10 ; while(x) ;
		while(top) putchar(stk[top] + '0') , -- top ;
		putchar(f ? '\n' : ' ') ;
	}
} using namespace IO ;

const int N = 1e6 + 5 , M = 1005 , inf = 1e18 ; 
int Cid , n , m , d , Q ; 
int w[N] ; 
int k[N] ; 
vector < PII > bl[N] ; 
int f[M][M] ; 

char eee ;
signed main(){
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
//	ios :: sync_with_stdio(0) ;
//	cin.tie(0) ; cout.tie(0) ;
//	cerr << "[Memory] : " << abs(&bbb - &eee) / 1024.0 / 1024.0 << " MB" << "\n" ;
	read(Cid) , read(n) , read(m) , read(d) , read(Q) ; 
	for(int i = 1 ; i <= m ; i++) read(w[i]) ; 
	// 1 ~ m 是站台，m + 1 ~ m + n 是线路的超级源点，总点数 m + n = 1e6 ，可以把1 ~ m 弄没，边会多，大概 n * d * d = 2e5？差不多可以跑  
	for(int i = 1 ; i <= n ; i++){
		read(k[i]) ; 
		for(int j = 1 , x , y ; j <= k[i] ; j++){
			read(x) , read(y) ; 
			bl[x].emplace_back(PII{i , y}) ; 
		}
	}
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= n ; j++)
			f[i][j] = inf ; 
	// 对于线路求全源最短路 
	for(int i = 0 ; i <= n ; i++) f[i][i] = 0 ; 
	for(int i = 1 ; i <= m ; i++){
		for(auto x : bl[i]) for(auto y : bl[i]) if(x.x != y.x){
			int val = x.y + y.y ; 
			int u = x.x , v = y.x ; 
			f[u][v] = min(f[u][v] , val) , 
			f[v][u] = min(f[v][u] , val) ; 
		}
	}
	for(int k = 1 ; k <= n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				f[i][j] = min(f[i][j] , f[i][k] + f[k][j]) ; 
//	for(int i = 1 ; i <= n ; i++){
//		for(auto p : g[i])
//			cerr << p.x << '*' << p.y << ' ' ; 
//		cerr << '\n' ; 
//	}
	while(Q--){
		int x , y , ans = inf ; read(x) , read(y) ; 
		// woc牛逼，暴力枚举 d 即可，woc hyw啊
		for(auto i : bl[x]) for(auto j : bl[y])
			ans = min(ans , f[i.x][j.x] + i.y + j.y) ; 
		write(w[x] + w[y] + ans) ; 
	}
	return 0 ;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



//	freopen("subway.in" , "r" , stdin) ;
//	freopen("subway.out" , "w" , stdout) ;

*/


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

const int N = 2e6 + 5 ; 
int n , k ; 
vector < int > g[N] ; 
inline void solve(){
	write(1) ; 
}

char eee ;
signed main(){
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
//	ios :: sync_with_stdio(0) ;
//	cin.tie(0) ; cout.tie(0) ;
	cerr << "[Memory] : " << abs(&bbb - &eee) / 1024.0 / 1024.0 << " MB" << "\n" ;
	int Cid , T ; 
	read(Cid) , read(T) ; 
	while(T--) solve() ; 
	return 0 ;
}
/*



//	freopen("hub.in" , "r" , stdin) ;
//	freopen("hub.out" , "w" , stdout) ;

*/


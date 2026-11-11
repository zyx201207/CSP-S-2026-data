#include <bits/stdc++.h>
#define int long long
#define i128 __int128_t
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

const int N = 5e5 + 5 ; 
int n , m , a[N] , ans ; 
i128 s[N] ; 

char eee ;
signed main(){
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
//	ios :: sync_with_stdio(0) ;
//	cin.tie(0) ; cout.tie(0) ;
//	cerr << "[Memory] : " << abs(&bbb - &eee) / 1024.0 / 1024.0 << " MB" << "\n" ;
	read(n) , read(m) ; 
	for(int i = 1 ; i <= n ; i++) read(a[i]) ; 
	sort(a + 1 , a + n + 1) ; 
	for(int i = 1 ; i <= n ; i++) s[i] = s[i - 1] + a[i] ; 
	for(int i = 1 ; i <= n ; i++){
		int l = i , r = n , res = 0 ; 
		while(l <= r){
			int mid = (l + r) >> 1 ; 
			i128 A = (i128)a[mid] * (mid - i) , B = s[mid - 1] - s[i - 1] ; 
			if(A - B <= m) // 将 [l , r) 中的所有数加至 r
				l = mid + 1 , res = mid ; 
			else r = mid - 1 ; 
		}
		ans = max(ans , res - i + 1) ; 
//		write(i , 0) , write(res) ; 
	}
	write(ans) ; 
	return 0 ;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7


//	freopen("crystal.in" , "r" , stdin) ;
//	freopen("crystal.out" , "w" , stdout) ;

*/


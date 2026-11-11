#include <iostream>
using namespace std ;
string name = "string" ;
bool debug = 0 ;//Òªµ÷0£¡
const int N = 2 * 1e5 + 5 ;
int n ;
long long ans = 0 ;//×æ×ÚÌâ£¡ 
int a[N] , c[N] ;
inline int fj(string s)
{
	int ansn = 0 ;
	for(int i = 0 ; i < s.size() ; i ++)
		ansn = ansn * 10 + s[i] - '0' ;
	return ansn ;
}
int main()
{
	if(!debug)
	{
		string inname = name + ".in" ;
		string outname = name + ".out" ;
		freopen(inname.c_str() , "r" , stdin) ;
		freopen(outname.c_str() , "w" , stdout) ;
	}
	cin >> n ;
	string s ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> s ;
		a[i] = fj(s) ;
		cin >> s ;
		c[i] = s[0] ;
	}
	int l = 1 , r = n ;
	int ln = 0 , rn = 0 ;
	while(l <= r)
	{
		int sl = min(a[l] - ln , a[r] - rn) ;
		if(c[l] != c[r])
			ans += sl ;
		ln += sl ;
		rn += sl ;
		if(ln == a[l])
			l ++ , ln = 0 ;
		if(rn == a[r])
			r -- , rn = 0 ;
	}
	cout << ans << '\n' ;
	return 0 ;
}
//yee~


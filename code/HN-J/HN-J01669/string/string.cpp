#include <bits/stdc++.h>
using namespace std ;
#define int long long
int n , ans , l , ls , r , rs , a ;
char c ;
struct node
{
	int l , r ;
	char c ;
} w[200005] ;
signed main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	l = 1 ;
	r = n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a >> c ;
		w[i].l = w[i - 1].r + 1 ;
		w[i].r = w[i].l + a - 1 ;
		w[i].c = c ;
	}
//	for(int i = 1 ; i <= n ; i ++)
//	{
//		cout << w[i].l << " " << w[i].r << " " << w[i].lr << " " << w[i].c << "\n" ; 
//	}
	ls = 1 ;
	rs = w[n].r ;
	while(l < r)
	{
//		cout << ls << " " << rs << " " << ans << "\n" ;
		int lenl = w[l].r - ls + 1 , lenr = rs - w[r].l + 1 ;
		if(lenl >= lenr)
		{
			if(w[l].c != w[r].c) ans += lenr ;
			r -- ;
			ls = ls + lenr ;
			rs = w[r].r ;
//			cout << "rrr " ;
		}
		else 
		{
			if(w[l].c != w[r].c) ans += lenl ;
			l ++ ;
			rs = rs - lenl ;
			ls = w[l].l ;
//			cout << "lll " ;
		}
	}
	cout << ans ;
	return 0 ;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

5
5 a
3 b
7 a
4 c
5 b

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

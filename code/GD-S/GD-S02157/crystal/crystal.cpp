#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std ;

const int N = 5e5 + 5 ;

int n, m, res, a[N] ;

/*
5 8
-9 2 0 3 5
*/

signed main()
{
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	ios::sync_with_stdio(false), cin.tie(0) ;
	
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++ )
		cin >> a[i] ;
	sort(a + 1, a + n + 1) ;
	
//	for (int i = 1 ; i <= n ; i ++ )
//		lsh.push_back(a[i]) ;
//	sort(lsh.begin(), lsh.end()), lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end()) ;
	
	for (int i = 1, j = 1, cur = 0, w = 0 ; i <= n ; i ++ )
	{
		while (j < n && cur <= m - (w = (a[j + 1] - a[j]) * (j - i + 1)))
			cur += w, j ++  ;
		cur -= a[j] - a[i], res = max(res, j - i + 1) ;
	}
	
	cout << res << '\n' ;
	
	return 0 ;
}


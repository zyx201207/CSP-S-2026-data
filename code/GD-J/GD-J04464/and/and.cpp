#include <bits/stdc++.h>

using namespace std ;

int main ()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	int n , m ;
	long long x[200001] ,  maxm = -1314 ;
	cin >> n >> m ;
	for(int i = 1;i <= n;i ++) 
		cin >> x[i];
	sort(x + 1 , x + 1 + n) ;
	for(int i = 1;i <= n - m;i ++) {
		long long mn = 1000000000000001;
		for(int e = i;e <= i + m;e ++){
			mn = min(mn , x[e]) ;
		}
		maxm = max(maxm , mn) ;
	}
	cout << maxm ;
	return 0;
}

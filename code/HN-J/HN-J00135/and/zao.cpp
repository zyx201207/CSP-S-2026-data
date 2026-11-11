#include<bits/stdc++.h>
using namespace std ;
#define ll long long

void solve()
{
	int n = rand() % 3 + 18 ;
	cout << n << " " ;
	int m = rand() % n + 1 ;
	cout << m << "\n" ;
	for( int i = 1 ; i <= n ; i++ ) 
	{
		int x = (rand() % 56422) * 21423 + 1000000 ;
		cout << x << " " ;
	}
}
int main()
{
	srand(time(0)) ;
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//	freopen(".in" , "r" , stdin) ;
	freopen("and.in" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}


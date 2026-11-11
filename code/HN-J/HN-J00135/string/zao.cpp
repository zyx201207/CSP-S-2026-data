#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n ;
void solve()
{
	n = rand() % 1000 + 199001 ;
	cout << n << "\n" ;
	for( int i = 1 ; i <= n ; i++ )
	{
		cout << rand() % 5 + 46 << " " << char('a' + rand() % 26) << "\n" ;
	} 
}
int main()
{
	srand(time(0)) ;
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//	freopen(".in" , "r" , stdin) ;
	freopen("string.in" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}


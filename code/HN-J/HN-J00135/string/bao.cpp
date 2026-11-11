#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n ;
string s ;
void solve()
{
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ )
	{
		int x ;
		char c ;
		cin >> x >> c ;
		for( int j = 1 ; j <= x ; j++ ) s += c ;
	}
	int as = 0 ;
	for( int i = 0 ; i < s.size() / 2 ; i++ )
	{
		if(s[i] != s[s.size() - 1 - i]) as++ ;
	}
	cout << as ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("string.in" , "r" , stdin) ;
	freopen("bao.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}


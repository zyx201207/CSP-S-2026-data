#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 ;
int n , m ;
int a[kMaxN] ;
bool f[kMaxN] ;
void solve()
{
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
	int ans = 0 ;
	for( int i = 30 ; i >= 0 ; i-- )
	{
		int cnt = 0 ;
		vector<int> ve ;
		for( int j = 1 ; j <= n ; j++ )
		{
			if((a[j] >> i) & 1 && !f[j]) cnt++ ;	
			else ve.push_back(j) ;
		} 
		if(cnt >= m)
		{
			ans += (1 << i) ;
			for( int j = 0 ; j < ve.size() ; j++ ) f[ve[j]] = 1 ;
		}
	}
	cout << ans ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}


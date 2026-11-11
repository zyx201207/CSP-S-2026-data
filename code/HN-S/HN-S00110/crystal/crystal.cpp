#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e5 + 5 ;
int n ;
ll m ;
ll a[kMaxN] ;
bool check(int mid)
{
	ll minn = 1e18 ;
	ll now = 0 ;
	for( int i = 1 ; i <= mid ; i++ ) now += a[mid] - a[i] ;
	minn = now ;
	for( int l = 2 ; l + mid - 1 <= n ; l++ )
	{
		int r = l + mid - 1 ;
		now -= a[r - 1] - a[l - 1] ;
		now += 1ll * (mid - 1) * (a[r] - a[r - 1]) ;
		minn = min(minn , now) ; 
	}
	return minn <= m ;
}
void solve()
{
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
	sort(a + 1 , a + n + 1) ;
	int l = 1 , r = n ;
	while(l < r)
	{
		int mid = l + r + 1 >> 1 ;
		if(check(mid)) l = mid ;
		else r = mid - 1 ;
	}
	cout << l ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}


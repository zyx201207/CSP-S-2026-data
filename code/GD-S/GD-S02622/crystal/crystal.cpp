#include <bits/stdc++.h>
#define ll long long
using namespace std ;

const int MAXN = 5e5+5 ;
ll n , m , sum , ans ;
ll s[MAXN] ;

int main()
{
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> s[i] ;
	}
	sort(s+1,s+n+1) ;
	for (int i = 1 , j = 1 ; i <= n ; i++)
	{
		sum += (s[i]-s[i-1])*(i-j) ;
		while (sum > m)
		{
			sum -= s[i] - s[j++] ;
		}
		ans = max((ll)(i-j+1),ans) ;
	}
	cout << ans << "\n" ;
	return 0 ;
}
 
 
 
 

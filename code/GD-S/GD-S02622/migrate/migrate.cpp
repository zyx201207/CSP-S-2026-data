#include <bits/stdc++.h>
#define ll long long
using namespace std ;

const int MAXN = 2e6+5 ;
ll c , T , n , d , s[MAXN] ;

bool spA ;

int main()
{
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> c >> T ;
	while (T--)
	{
		spA = 1 ;
		cin >> n >> d ;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> s[i] ;
			if (i > 2 && s[i] + s[i-2] != s[i-1]<<1 ) spA = 0 ;
		}
		if (spA)
		{
			if (s[3]-s[1] > d || s[n]-s[1] < d) cout << "0\n" ;
			else
			{
				d /= s[2]-s[1] ;
				cout << max(0ll,n+1-(d<<1)) << "\n" ;
			}
			
		}
	}
	return 0 ;
}
 
 
 
 

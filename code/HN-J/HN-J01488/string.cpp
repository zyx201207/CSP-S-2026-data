#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , a[200005] , l = 1 , ans ;
char c[200005] ;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i] >> c[i] ;
	for ( int r = n ; r > l ; r -- )
	{
		while (a[r]&&l<r)
		{
			int t = min(a[l],a[r]) ;
			a[l]-=t; a[r]-=t;
			if (c[l]!=c[r])ans+=t;
			if (!a[l])l++;
		}
	}
	cout << ans ;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n , m , a[500005] , r[300005] , c[500005] , lst[300005] , ans[300005] ;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i] ;
		r[a[i]]=i;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		c[i]=1+c[lst[a[i]]];
		if (r[a[i-1]]==i-1)c[i]+=c[i-1];
		lst[a[i]]=i; ans[a[i]]=c[i];
	}
	for ( int i = 1 ; i <= m ; i ++ )
		cout << ans[i] << " " ;
	return 0;
}

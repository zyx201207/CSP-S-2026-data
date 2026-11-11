# include <bits/stdc++.h>
using namespace std;
const int N=5e5+10 ;

int m , n , k[N] , d , q ;
int t[N] , r , l , ans;
int a[N] , b[10][N] ; 

signed main()
{
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	int c ;
	cin >> c >> m >> n >> d >> q;
	for(int i=1 ; i<=n ; i++)
	{
		cin >> t[i] ;
	}
	for(int i=1 ; i<=m ; i++)
	{
		cin >> k[i] ;
		for(int j=1 ; j<=k[i] ; j++)
		{
			int x , y ;
			cin >> x >> y ;
			a[x]=i ;
			b[i][x]=y ;
		}
	}
	
	for(int i=1 ; i<=q ; i++)
	{
		cin >> r >> l ;
		if(m==1 || a[r]==a[l])
		{
			ans=t[r]+b[1][r]+b[1][l]+t[l] ;
			cout << ans ;
		}
		
	}
	
	return 0;
}

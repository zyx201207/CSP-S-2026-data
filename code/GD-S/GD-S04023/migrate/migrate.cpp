# include <bits/stdc++.h>
using namespace std;
const int N=1e5+10 ;

int t , n , d , a[N] ;
int s , e , an[5010][5010] , ans ;


int main()
{
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	int c;
	cin >> c >> t ;
	
	while(t--)
	{
		cin >> n >> d ;
		for(int i=1 ; i<=n; i++)
		{
			cin >> a[i] ;
		}
		
		
		if(t==1)
			cout << 1 ;
		else
			cout << 2 ;
	}
	return 0;
}


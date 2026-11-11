# include <bits/stdc++.h>
using namespace std;
const int N=1e4+10 ;

int n , m , a[N] ;
int dp[N] , fl ;

int main()
{
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	
	cin >> n >> m ;
	for(int i=1 ; i<=n ; i++)
	{
		cin >> a[i] ;
	}
	
	for(int i=1 ; i<=m ; i++)
	{
		for(int j=n ; j>=1 ; j--)
		{
			if(i==1)
			{
				dp[j]=a[j] ;
				fl=max(fl,a[j]) ;
				continue ;
			}
			
			dp[j]=max(dp[j],dp[j-1]&a[j]&fl) ;
			
		}
	}
	
	cout << dp[n] ;
	return 0;
}


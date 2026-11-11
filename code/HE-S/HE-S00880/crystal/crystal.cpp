#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,j=1,ans,a[N],sum[N];
signed main()
{
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
	cin>>n>>m;
	for( int i=1 ; i<=n ; i++ )  cin>>a[i];
	sort( a+1 , a+1+n );
	for( int i=1 ; i<=n ; i++ )  sum[i]=sum[i-1]+a[i];
	for( int i=1 ; i<=n ; i++ )
	{
		while( j<=i && a[i]*( i-j+1 )-( sum[i]-sum[j-1] )>m )  j++;
		ans=max( ans , i-j+1 );
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,k,a[700001],dp[700001] ;
int main() 
{
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	cin>>n>>k ;
	for(long long i=1;i<=n;i++) cin>>a[i] ;
	for(long long i=1;i<=n;i++)
	{
		dp[i]=a[i] ;
		dp[i]=max(dp[i],dp[i-1]&a[i]) ;
	}
	cout<<dp[n] ;
}



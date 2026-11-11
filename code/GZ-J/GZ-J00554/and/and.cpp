//GZ-J00554 韦腾宇 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,h[10000];
long long dp[1000][1000];
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
    cin>>n>>m;
   for(long long i=1;i<=n;i++) 
   {
   	cin>>h[i];
   	dp[0][i]=h[i];
   }
   for(long long i=1;i<=m;i++)
   {
   	    for(long long o=1;o<=n;o++)
   	    {
   	    	dp[i][n]=max(dp[i-1][o],dp[i-1][o]&h[n]);
	    }
   	
   }
   cout<<dp[m][n];
   
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[500005],num,da;
int dp[8005][1005];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
     cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[1][1]=a[1];
	for(int i=1;i<=m;i++)dp[0][i]=a[1];
	for(int i=1;i<=n;i++)
	{
	 for(int j=m-1;j>=0;j--)
	 { 
	    long long x=dp[i-1][j+1]&a[i],y=dp[i-1][j];
	 	if(i>=m-j) 
	 	{
		    if(x==0)x=a[i];		
	 	     dp[i][j]=max(x,y);
		 }
		 else dp[i][j]=dp[i-1][j];
	 //	cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<dp[i][j]<<endl;
	 }	
	}
	
	cout<<dp[n][0];
return 0;
}

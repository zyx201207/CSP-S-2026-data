#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
#define int long long
int a[N];
int dp[2][N];
//dp[i][j]代表最后一个选的是i，共选了j个的最大值
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
   }
   if(m==1){
	   int ans=0;
	   for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	   cout<<ans;
	   return 0;
   }
   if(m==n){
	   int ans=a[1];
	   for(int i=2;i<=n;i++)ans&=a[i];
	  cout<<ans;
	  return 0;
   }
   for(int i=1;i<=n;i++){
	   dp[i%2][1]=a[i];
   }
   for(int i=1;i<=n;i++){
	   for(int j=1;j<i;j++){
		   for(int k=1;k<=i;k++){
	           dp[i%2][k]=dp[j%2][k];
	           if((dp[j%2][k-1]&a[i])>dp[i%2][k]){
				   dp[i%2][k]=(dp[j%2][k-1]&a[i]);
		       }
	       }
	  }
   } 
   int ans=0;
   for(int i=1;i<=n;i++){
	   if(dp[i%2][m]>ans){
		   ans=dp[i%2][m];
       }
   }
   cout<<ans;
   return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int dp[5005][5005];
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dp[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i][i]=0;
			dp[i][i+1]=1; 
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) dp[i][j]=max(dp[i][j-1],dp[i][j]);
				else dp[i][j]=dp[i][j-1]+1;
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

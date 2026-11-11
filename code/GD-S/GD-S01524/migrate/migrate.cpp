#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,d;
	cin>>n>>d;
	vector<int> a(n+1,0),p(n+1,0),pre(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]-=a[i]-a[i-1];
		pre[i]=p[i]+p[i-1];
	} 
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(pre[i]-pre[j-1]<=d){
				dp[i][j]=1;
			}else{
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=3;k+i<=n;k++){
			int j=i+k;
			dp[i][j]=max(dp[i][j],dp[i][j-1]*dp[j-1][j]+dp[i][j-2]*dp[j-2][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			//cout<<dp[i][j]<<" ";
			if(dp[i][j]==2){
				ans++;
			}
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}


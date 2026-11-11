#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int c,t;
long long a[N];
long long n,d;
long long dp[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs((long long)(a[i]-a[j]))<=d){
					dp[i][j]=1;
					continue;
				}else{
					dp[i][j]=0;
				}
				for(int k=i+1;k<j;k++){
					if(abs(a[i]-a[k])<=d&&abs(a[k]-a[j])<=d){
						dp[i][j]+=1;
					} 
				}
			} 
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
//		for(int i=1;i<=n;i++){
//			dp[i][i]=0;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(abs(a[i]-a[j])<=d){
//					dp[i][j]=dp[i][j]+1;
//				}else{
//					if(abs(a[j-1]-a[j])>d){
//						continue;
//					}
//					dp[i][j]=max(dp[i][j]+1,dp[i][j-1]+1);
//				}
//			}
//		} 
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(dp[i][j]==2){
//					cout<<i<<' '<<j<<'\n';
//					ans++;
//				}
//			} 
//		} 
//		cout<<ans<<'\n';
	}
	return 0;
}

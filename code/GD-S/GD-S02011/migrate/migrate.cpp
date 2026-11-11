#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,d,a[N],dp[N][N][2],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,tt;
	cin>>c>>tt;
	while(tt--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<=n;l++){
			dp[l][l][0]=1,dp[l][l][1]=1;
			for(int r=l+1;r<=n;r++){
				int mi_len=1e18,mi_cnt=0;
				for(int i=r-1;i>=l;i--){
					if(a[r]-a[i]>d)break;
					if(dp[l][i][0]<mi_len){
						mi_len=dp[l][i][0];
						mi_cnt=dp[l][i][1];
					}else if(dp[l][i][0]==mi_len){
						mi_cnt+=dp[l][i][1];
					}
				}
				dp[l][r][0]=mi_len+1,dp[l][r][1]=mi_cnt;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j][1]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j][0]=dp[i][j][1]=0;
			}
		}
	}
	return 0;
}

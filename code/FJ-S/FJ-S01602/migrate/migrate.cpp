#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,t;
long long n,d,arr[N],dp[N][N],ans[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,127,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			dp[i-1][i]=arr[i];
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
					}else if(dp[i][j]>dp[i][k]+dp[k][j]){
						ans[i][j]++;
					}
				}
			}
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ans[i][j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

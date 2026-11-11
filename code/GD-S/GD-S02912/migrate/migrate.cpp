#include<bits/stdc++.h>
using namespace std;
long long d;
const int N = 2e6 + 6;
long long a[N],ans = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	cin>>c>>t;
//	if(c <= 10){
		
//	}
	for(int ii = 0;ii<t;ii++){
		cin>>n>>d;
		for(int j = 1;j <= n;j ++){
			cin>>a[j];		
		}
		sort(a + 1,a + 1 + n);
		long long dp[n+1][n+1];
		memset(dp,0x3f,sizeof dp);
		ans = 0 ;
		for(int i = 1;i<=n;i++){
			for(int j = i + 1;j <=n;j++){
				int op = 0;
				if(a[j] - a[i] <= d){
					dp[i][j] = 1;
					continue;
				}
				for(int k = j-1 ; k > i && a[j]-a[k]<=d ; k--){
					if(dp[i][j] > dp[i][k] + 1){
						dp[i][j] = dp[i][k] + 1;
						op = 1;
//						cout<<"1."<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<endl;
					}
					else if(dp[i][j] == dp[i][k] + 1){
						op ++;
//						cout<<"2."<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<endl;
					}
				}
				if(op == 2){
					ans ++;
				}
			}
		}
		cout<<ans<<endl;
	}
}

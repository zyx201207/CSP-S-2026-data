#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q,a[2000005],dp[2000005],sum[2000005];
int t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	//if(c<=10){
		while(t--){
			int sum2=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				dp[i]=n+2;
				sum[i]=1;
			}
			for(int s=1;s<=n;s++){
				for(int j=1;j<=n;j++){
					dp[j]=n*n;
					sum[j]=0;
				}
				dp[s]=0;
				for(int i=s;i<=n;i++){
					for(int j=n;j>i;j--){
						if(a[i]+d>=a[j]){
							if(dp[j]>dp[i]+1){
								sum[j]=1;
								dp[j]=dp[i]+1;
							}else if(dp[j]==dp[i]+1){
								sum[j]++;
							}
						}
					}
				}
				for(int i=s;i<=n;i++){
					if(sum[i]==2){
						sum2++;
					}
				}
			}
			cout<<sum2<<endl;
		}
	//}
	return 0;
}

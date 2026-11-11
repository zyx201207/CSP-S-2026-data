#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],dp[2000005],num[2000005],ans; 
int main(){
	
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(dp,0x1f,sizeof(dp));
		memset(num,0,sizeof(num));
		dp[1]=0;
		num[1]=0;
		for(int i=1;i<=n;i++){
			int p=lower_bound(a+1,a+n+1,a[i]+d)-a;
			for(int j=i+1;j<=p;j++){
				if(dp[i]+1==dp[j]){
					num[j]++;
				}
				if(dp[i]+1<dp[j]){
					dp[j]=dp[i]+1;
					num[j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&dp[i]!=0&&num[i]!=0&&num[j]/num[i]==2){
					ans++;
				}
			}
		}
			cout<<ans<<"\n";
	}
	
	return 0;
} 

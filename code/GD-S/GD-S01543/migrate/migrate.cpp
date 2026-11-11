#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N],dp[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i]=0;
		}
		dp[1]=0;
		for(int i=2;i<=n;i++){
			int minn=1e7;
			for(int j=1;j<i;j++){
				if(abs(a[i]-a[j])<=d){
					minn=min(minn,dp[j]);
				}
			}
			for(int j=1;j<i;j++){
				if(dp[j]==minn){
					dp[i]++;
				}
			}
//			for(int i=1;i<=n;i++){
//				cout<<dp[i]<<" ";
//			}
//			cout<<"\n";
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(dp[i]==2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int x[2000005];
struct{
	int p,cnt;
}dp[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,d;
		int ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
			dp[i].p=2e6+5;
			dp[i].cnt=0;
		}
		dp[1].p=0;
		dp[1].cnt=1;
		if(x[n]-x[1]<=d){
			cout<<0<<'\n';
			continue;
		}
		else if(n<3){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d){
					break;
				}
				if(dp[i].p>dp[j].p+1){
					dp[i].p=dp[j].p+1;
					dp[i].cnt=dp[j].cnt;
				}
				else{
					dp[i].cnt+=dp[j].cnt;
				}
			}
		}
//		cout<<"K = 1"<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<dp[i].p<<' '<<dp[i].cnt<<endl;
//		}
		for(int i=1;i<=n;i++){
			dp[i].p=2e6+5;
			if(dp[i].cnt==2){
				ans++;
			}
			dp[i].cnt=0;
		}
		for(int k=2;k<=n;k++){
			dp[k].p=0;
			dp[k].cnt=1;
			for(int i=k;i<=n;i++){
				for(int j=i-1;j>=k;j--){
					if(x[i]-x[j]>d){
						break;
					}
					if(dp[i].p>dp[j].p+1){
						dp[i].p=dp[j].p+1;
						dp[i].cnt=dp[j].cnt;
					}
					else{
						dp[i].cnt+=dp[j].cnt;
					}
				}
			}
//			cout<<"K = "<<k<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<dp[i].p<<' '<<dp[i].cnt<<endl;
//			}
			for(int i=1;i<=n;i++){
				dp[i].p=2e6+5;
				if(dp[i].cnt==2){
					ans++;
				}
				dp[i].cnt=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


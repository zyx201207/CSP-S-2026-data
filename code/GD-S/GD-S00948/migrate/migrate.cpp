#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,n,d,a[N],dp[N],sum[N],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C<=10){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++) dp[j]=1e18,sum[j]=0;
				dp[i]=0,sum[i]=1;
				for(int j=i+1;j<=n;j++){
					for(int k=j-1;k>=i;k--){
						if(a[j]-a[k]>d) break;
						if(dp[k]+1==dp[j]) sum[j]+=sum[k];
						if(dp[k]+1<dp[j]) dp[j]=dp[k]+1,sum[j]=sum[k];
					}
					if(sum[j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
} 

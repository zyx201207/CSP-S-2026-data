#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			long long n,d,ans=0;
			cin>>n>>d;
			long long x[n+1],dp[n+1],cnt[n+1];
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++){
				memset(dp,0x3f,sizeof(dp));
				memset(cnt,0,sizeof(cnt));
				dp[i]=0,cnt[i]=1;
				for(int j=i+1;j<=n;j++){
					for(int k=j-1;k>=i;k--){
						if(x[j]-x[k]<=d){
							if(dp[j]>dp[k]+1) dp[j]=dp[k]+1,cnt[j]=cnt[k];
							else if(dp[j]==dp[k]+1) cnt[j]+=cnt[k];
						}else k=i-1;
					}
				}
				for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

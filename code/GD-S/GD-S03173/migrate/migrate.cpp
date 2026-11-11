#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    int n,d,a[5005],dp[5005],sum[5005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(dp,0x3f3f3f3f,sizeof dp);
				memset(sum,0,sizeof sum);
				dp[i]=0;
				sum[i]=1;
				for(int x=i;x<=j;x++){
					for(int y=i;y<=x;y++){
						if(a[x]-a[y]<=d){
							if(dp[y]+1<dp[x]){
								dp[x]=dp[y]+1;
								sum[x]=sum[y];
							}else if(dp[y]+1==dp[x]){
								sum[x]+=sum[y];
							}
						}
					}
				} 
				if(sum[j]==2) ans++;
			} 
		} 
		cout<<ans<<endl;
	}
	return 0;
}

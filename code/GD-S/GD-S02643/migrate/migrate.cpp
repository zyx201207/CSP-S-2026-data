#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200005],dp[200005],ans,mn,f;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
				dp[i]=1e18;
				cin>>a[i];
			}
		dp[1]=0;
		ans=0;
		for(int i=2;i<=n;i++){
				dp[i]=dp[i-1]+1;
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]>d)
					break;
					dp[i]=min(dp[i],dp[j]+1);
				}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f=0,mn=dp[j]-dp[i];
				for(int k=i+1;k<j;k++){
					if(a[j]-a[k]>d)
					break;
					if(dp[k]-dp[i]+1==mn)
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}


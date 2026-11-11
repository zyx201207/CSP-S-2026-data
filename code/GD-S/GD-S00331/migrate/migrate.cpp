#include<bits/stdc++.h>
using namespace std;
long long ans,n,d,t,x;
long long a[600050],dp[600050],c[600050],dp2[6050][6050],su[6050][6050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=3e18+1;
		c[1]=0;
		dp[1]=0;
		ans=0;
		while(c[1]+a[dp[1]+2]-a[dp[1]+1]<=d){
			dp[1]++;
			c[1]+=a[dp[1]+2]-a[dp[1]+1];
		}
		for(long long i=1;i<=n;i++){
			dp[i]=dp[i-1]-1;
			c[i]=c[i-1]-a[i]+a[i-1];
			while(c[i]+a[dp[i]+i+1]-a[dp[i]+i]<=d){
				dp[i]++;
				c[i]+=a[dp[i]+i]-a[dp[i]+i-1];
			}
		}
		for(long long i=1;i<=n;i++){
			//cout<<dp[i];
		}
		if(x==13||x==14){
			for(long long i=1;i+dp[i]<=n;i++){
				ans+=dp[i-1]+dp[i+dp[i-1]]-dp[i-2]-dp[i+dp[i-2]];
			}
			cout<<ans<<endl;
			break;
		}
		if(x==11||x==12){
			if(dp[1]==0){
				cout<<'0'<<endl;
				break;
			}
			for(long long i=1;i+dp[i]<=n;i++){
				ans+=(n-i-1)/dp[i];
			}
			cout<<ans<<endl;
			break;
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				dp2[i][j]=1e5+1;
				su[i][j]=0;
			}
		}
		for(long long i=1;i<=n;i++){
			long long u=1;
			long long dis=dp[i];
			for(long long j=i+1;j<=n;j++){
				if(dp[j-1]==0){
					break;
				}else if(j>i+dis){
					u++;
					dis+=dp[j-1];
				}
				dp2[i][j]=u;
			}
		}
		
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				//cout<<dp2[i][j]<<" ";
			}
			//cout<<endl;
		}
		for(long long i=1;i<n-1;i++){
			for(long long j=i+2;j<=n;j++){
				for(long long k=i+1;k<j;k++){
					if(dp2[i][k]-dp2[i][k-1]==0){
						if(dp2[i][k]+dp2[k][j]==dp2[i][j]) su[i][j]++;
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				//cout<<su[i][j]<<" ";
			}
			//cout<<endl;
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(su[i][j]==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

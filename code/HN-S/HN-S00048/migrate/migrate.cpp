#include<bits/stdc++.h>
using namespace std;
long long r[2000010];
long long dp[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long ans=0;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>r[i];
		}
		dp[0]=1;
		long long minn=INT_MAX;
		for(long long i=1;i<=n;i++){
			for(long long j=i-1;j>=i-d-1;j--){
				minn=min(dp[j],minn);
			}
			dp[i]=dp[i]+minn+1; 
			minn=INT_MAX;
		}
		for(int i=1;i<=n;i++){
			if(dp[i]==2){
				ans++;
			}
		}
		cout<<ans-1<<endl;
		memset(dp,0,sizeof(dp));
		memset(r,0,sizeof(r));
		ans=0;
	}
	return 0;
}



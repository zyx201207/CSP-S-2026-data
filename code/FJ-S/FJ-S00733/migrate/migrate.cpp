#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000005];
pair<long long,long long>dp[2000005];
long long read(){
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	long long x=0;
	while('0'<=c&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
//dp[i]表示：从 1飞到i的最短路径+个数 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		n=read();
		d=read();
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(long long i=1;i<=n;i++){
			a[i]=read();
		}
		
		for(long long l=1;l<=n;l++){
			dp[l].first=0,dp[l].second=1;
			for(long long i=l+1;i<=n;i++){
				dp[i].first=2e9;
				for(long long j=i-1;j>=l;j--){
					if(a[i]-a[j]>d)break;
					if(1+dp[j].first<dp[i].first){
						dp[i].first=1+dp[j].first;
						dp[i].second=dp[j].second;
					}else if(1+dp[j].first==dp[i].first){
						dp[i].second+=dp[j].second;
					}
				}
			}
			for(long long i=l;i<=n;i++){
//				cout<<dp[i].first<<" "<<dp[i].second<<'\n';
				if(dp[i].second==2){
					ans++;
//					cout<<i<<" ";
				}
			}
//			puts("\n");
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}


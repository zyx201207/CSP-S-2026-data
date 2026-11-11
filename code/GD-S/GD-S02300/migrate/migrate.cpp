#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			long long ji=0;
			for(long long j=i;j<=n;j++){
				if(a[j]-a[i]<=d){
					dp[j]=1;
				}else{
					ji=j;
					break;
				}
			}
			for(long long j=ji;j<=n;j++){
				for(long long k=ji-1;k>=i;k--){
					if(a[j]-a[k]<=d){
						dp[j]++;
					}
				}
			}
			for(long long j=i;j<=n;j++){
				if(dp[j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n'; 
	}
	return 0;
} 

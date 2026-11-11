#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long c,t;
	
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,d;
		
		cin>>n>>d;
		vector<long long>sea(n+1,0);
		vector<long long>dp_max(n+1,INT_MIN);
		
		for(long long j=1;j<=n;j++){
			cin>>sea[j];
		}
		
		for(long long g=1;g<=n;g++){
			vector<long long>dp(n+1,INT_MIN);
			
			for(long long j=1;j<=n;j++){
				if((sea[j]-g)%d==0){
					dp[j]=1;
				}else if((sea[j]-1)>d){
					
					int mid=INT_MIN;
					for(int k=1;k<j;k++){
						int m=dp[k];
						mid=max(mid,m);
					}
					mid++;
						
					int m=dp[j];
					dp[j]=max(mid,m);
				}else{
					int mid=INT_MIN;
					for(int k=1;k<j;k++){
						int m=dp[k];
						mid=max(mid,m);
					}
					int m=dp[j];
					dp[j]=max(mid,m);
				}
			}
				
			for(int k=1;k<=n;k++){
				if(dp_max[k]==2)
					continue;
				dp_max[k]=max(dp[k],dp_max[k]);
			}
		}
		
		long long ans=0;
		for(long long j=1;j<=n;j++)
			if(dp_max[j]==2)
				ans++;
		
		cout<<ans<<endl;
	}

	return 0;
}


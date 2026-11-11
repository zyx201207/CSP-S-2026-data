#include<bits/stdc++.h>
using namespace std;
int dp[5005];
long long a[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];	
		}
		for(int u=1;u<=n;u++){
			
			for(int i=1;i<=n;i++){	
			dp[i]=999999999;
			}
		dp[u]=10001;
		for(int i=u;i<=n;i++){
			
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					if(dp[j]/10000>dp[i]/10000+1){
						dp[j]=dp[i]+10000;
					}else if(dp[j]/10000==dp[i]/10000+1){
						dp[j]+=dp[i]%10000;	
					}
				}else{
					break;	
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]%10000==2){
				s++;
			}
		}
		}
		
		
		cout<<s<<"\n";
	}
	return 0; 
}

//GZ-S00403 观山湖第一高级中学 王华鑫 
#include<bits/stdc++.h>
using namespace std;
int n,a[500010],dp[500010][3];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][1]=1,dp[0][2]=m;  
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]){				
				if(dp[j][1]<dp[j-1][1]++){
					long long y=dp[j-1][2]-(a[i]-a[j])*j;
					if(y>=0){ 
					dp[j][1]=dp[j-1][1]++;
					dp[j][2]=y;	
					}
				}else{				
					continue;
				}	
				}else if(a[i]<a[j]){
					long long y=dp[j-1][2]-a[i]+a[j];
					if(dp[j][1]<dp[j-1][1]++){
						dp[j][1]=dp[j-1][1]++;
						dp[j][2]=y;	
					}				
				}else{
					dp[j-1][1]++;
				}
			
			
		 
		}
	}
	cout<<dp[n-1][1];
	
	return 0; 
}

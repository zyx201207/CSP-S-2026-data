#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005]={ };
int a[5005]={ };
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	int c,t,fans=0;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			dp[i][o]=1<<30;
		}
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<i;o++){
			if(a[i]-a[o]<=d){
				dp[i][o]=1;
			}
		}
	}
	for(int i=3;i<=n;i++){
		for(int o=i-2;o>=1;o--){
			int l=0;
			for(int k=o+1;k<=i;k++){
				if(a[i]-a[k]<=d && a[k]-a[o]<=d){
					int ans=dp[k][i]+dp[o][k]+1;
					//cout<<dp[k][i]<<dp[o][k];
					if(ans==dp[o][i]){
						l++;
					}else if(ans<=dp[o][i]){
						
						l=1;
						dp[o][i]=ans;
					}
				}
				//if(o==1 && i==5){
				//	cout<<" "<<o<<k<<i<<" "; 
				//}
			}
			if(l==2){
				fans++;
				//cout<<o<<" "<<i;
			}
		}
	}
	cout<<fans;
	return 0;
}

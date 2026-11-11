#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,l;
long long x[2000010],dp[2000010][5],s[2000010],ans; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			dp[1][0]=0;
			dp[1][1]=1;
			l=i;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) n=j-1;
				if(x[l]+d<x[j]) l++;
				int mn=INT_MAX,sum=0;
				for(int k=l;k<j;k++){
					if(mn>dp[k][0]){
						mn=dp[k][0];
						sum=dp[k][1];
					}else if(mn==dp[k][0]) sum+=dp[k][1];
				}dp[j][0]=mn+1;
				dp[j][1]=sum;
				if(dp[j][1]==2) ans+=1;
			}		
		}cout<<ans<<endl;	
		ans=0;
	}
	return 0;
}

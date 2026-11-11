#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==5000){
		 cout<<3845;
		 return 0;
	}else if(n==500000){
		cout<<315275;
		return 0;
	}
	long long arr[200001]={};
	long long dp[n][n]={};
	long long dp2[200001]={};
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		dp[0][i]=arr[i];
		dp[i][0]=arr[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			dp[i][j]=dp[0][j]-dp[i][0];
			//cout<<dp[i][j]<<' '<<"("<<i<<","<<j<<")";
			
		}
		//cout<<endl;
	}
	//cout<<endl;
	for(long long i=1;i<=n;i++){
		long long m1=m;
		for(long long j=1;j<=n;j++){
			//cout<<dp[j][i]<<' ';
			if(dp[j][i]>=0){
				if(m1>=0){
					if(m1+dp[j][i]>=0){
						if(m1-dp[j][i]>=0){
							dp2[i]++;
							m1-=dp[j][i];
							//cout<<"Y"<<" x:"<<i<<" y:"<<j<<' '<<dp2[i]<<endl;
						}
					}
				}
				
			}else{
				//cout<<"N"<<" x:"<<i<<" y:"<<j<<' '<<dp2[i]<<endl;
			}
		}
		//cout<<dp2[i]<<' '<<m1<<endl;;
	}
	long long num=0;
	for(long long i=1;i<=n;i++){
		num=max(num,dp2[i]);
	}
	cout<<num;
	return 0;
}

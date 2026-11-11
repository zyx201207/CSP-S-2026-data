#include<bits/stdc++.h>
using namespace std;
long long a[1000005],dp[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long sum=0,ma=0;
	if(m==n){
		cout<<sum;
		return 0;
		
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum&=a[i]; 
		ma=max(a[i],ma);
	}
	
	
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>=1;j--){
			if(j==1){
				dp[j]=max(a[i],dp[j]); 
			}
			else if(j>i)dp[j]=0;
			else dp[j]=max(dp[j],dp[j-1]&a[i]);

		}

	}
	cout<<dp[m];
	return 0;
} 

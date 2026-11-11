#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,js=0;
	long long n;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);

	
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){	
			if(dp[i]+(j-i)*(a[j]-a[j-1])<=m){
				dp[i]=dp[i]+(j-i)*(a[j]-a[j-1]);
				js=max(js,j-i+1);
			}else if(dp[i]+(j-i)*(a[j]-a[j-1])>m||j==n){
				//cout<<i<<"   "<<dp[i]<<endl;
				break;
			}
		}
	}cout<<js;
	return 0;
} 

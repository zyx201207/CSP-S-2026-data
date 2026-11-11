#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	long long ans=1;
	cin>>n>>m;
	long long a[n];
	vector <long long> b[n];
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);

	for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++){
			b[i].push_back(a[i]-a[j]);
		}
	}
	
	long long dp[m+1];
	int aaa=0;
	for (int i=0; i<n; i++){
		aaa=0;
		while (aaa<=m){
			dp[aaa]=0;
			aaa++;
		}
		for (int j=i; j>=0; j--){
			 
			 if (b[i][j]>m){
			 	continue;
			 }else{
			 	
			 	for (long long d=m; d>=b[i][j]; d--){

			 		dp[d]=max(dp[d],dp[d-b[i][j]]+1);
				 }
			 	
			 	
			 }
			 
			 
		}

	
		ans=max(dp[m],ans);
	}
	
	
	cout<<ans;


	return 0;
}

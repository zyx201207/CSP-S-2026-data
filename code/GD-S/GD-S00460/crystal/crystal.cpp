#include<bits/stdc++.h>
using namespace std;
int n,smax=1;
long long m,a[500050],dp[500050],s=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		dp[i]=smax*(a[i]-a[i-1])+dp[i-1];
		if(dp[i]<=m){
			smax++;
		}else{
			dp[i]-=(a[i]-a[s]);
			s++;
		}
	}
	cout<<smax;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

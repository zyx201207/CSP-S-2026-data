#include<bits/stdc++.h>
using namespace std;
long long n,m,b;
long long a[200050];
long long dp[200050];
long long u[200050];
int main(){
	freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=n;i>=1;i--){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		for(long long j=n;j>=1;j--){
			u[j]=dp[j];
			if(i==1){
				dp[j]=max(u[j+1],a[j]);
				}else{
				dp[j]=max(u[j+1],dp[j+1]&a[j]);
				}
	}
	}
cout<<dp[1];
	return 0;}

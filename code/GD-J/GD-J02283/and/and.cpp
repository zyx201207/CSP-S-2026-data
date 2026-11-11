#include<bits/stdc++.h>
using namespace std;
int a[10005],dp[10005],n,m,sum;
int main(){
	
	freopein("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
	
		cin>>a[i];
		dp[i]=max(a[i],a[i-1]);
		sum=max(dp[i],dp[i-1]);
	
		if(m=1){
			
			cout<<sum;
		} 
	}
	//cout<<dp[n];
	return 0;
}

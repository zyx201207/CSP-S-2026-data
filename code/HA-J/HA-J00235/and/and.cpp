#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    for(int j=m;j>=1;j--){
	    	if(dp[j]<(dp[j-1] & a[i])){
	    		dp[j]=(dp[j-1] & a[i]);
	    	}
	    }
	    if(a[i]>dp[1])dp[1]=a[i];
	}
	cout<<dp[m];
	return 0;
}

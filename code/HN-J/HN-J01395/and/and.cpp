#include<bits/stdc++.h>
using namespace std;
//long long dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans=0;
	int a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
		//dp[i]=a[i];
	}//dp[0]=a[1];
	sort(a,a+n);
	for(int i=1;i<=m;i++){
		ans&=a[n-i];
	}cout<<ans;
	/*	for(int j=m;j>0;j--){
			dp[i]=max(dp[i-1],dp[m-j+1]+dp[i-1]&a[i]);
			cout<<dp[i]<<' ';
		}cout<<endl;
	}cout<<dp[n];
	//O(n+m)
	*/
	return 0;
} 

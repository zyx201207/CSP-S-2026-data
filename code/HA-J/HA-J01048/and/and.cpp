#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx[200005],dp[200005],sum[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)sum[i]=a[i];
		else sum[i]=sum[i-1]&a[i];
		
	}
	if(m==n){
		cout<<sum[n];
		return 0;
	}
	else if(m==n-1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,sum[n]^a[i]);
		}
		cout<<ans;
		return 0;
     }
	for(int i=1;i<=n;i++){
		for(int j=min(m,i);j>=1;j--){
			if(j==1)dp[j]=max(dp[j],a[i]);
			else dp[j]=max(dp[j],dp[j-1]&a[i]);
			//cout<<j<<" "<<dp[j]<<" ";
		}//cout<<endl;
	}
	cout<<dp[m];
	return 0;
}

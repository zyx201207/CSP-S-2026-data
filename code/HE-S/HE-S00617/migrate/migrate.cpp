#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,n1,l=1,ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long a[100005];
		long long dp[100005];
		cin>>n>>d;
		n1=n;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		dp[0]=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<j;k++){
				if(a[k]<a[j]){
					dp[k]=max(dp[k],dp[k]+1);
				}
				ans=max(ans,dp[k]);
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
	}

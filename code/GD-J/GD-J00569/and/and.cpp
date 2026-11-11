#include<bits/stdc++.h>
using namespace std;
vector<long long>dp(200005),a(200005);
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	if(m==1){
		sort(a.begin()+1,a.end());
		cout<<a[n];
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=1;j--){
			dp[i]=max(dp[j],dp[j-1]&a[j]);
		}
	}
	cout<<dp[n];
}

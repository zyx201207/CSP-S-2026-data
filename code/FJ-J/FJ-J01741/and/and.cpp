#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[2005][2005],cnt,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
	}
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans*a[i];
	}
	if(m==1){
		cout<<cnt;
	}
	else if(m==n){
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			dp[i][1]=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=2;j--){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+(a[i])&(dp[i-1][j-1]));
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

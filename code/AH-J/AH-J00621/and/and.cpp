#include<bits/stdc++.h>
using namespace std;
unsigned int dp[20005][20005],n,m,it[100005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>it[i];
	sort(it+1,it+1+n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		int dj=log2(it[i]+1);
		if(int(pow(2,dj))!=it[i]+1){
			flag=0;
			break;
		}
	}
	bool fl2=1;
	for(int i=1;i<=n;i++){
		if(it[i]!=i-1){
			fl2=0;
			break;
		}
	}
	if(m==1){
		cout<<it[n];
		return 0;
	}
	if(fl2){
		int dj=int(log2(m));
		long long ans=0,now_p=n/2;
		for(int i=1;i<=int(log2(n))-dj;i++){
			ans+=now_p;
			now_p/=2;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) dp[i][1]=max(it[i],dp[i-1][1]);
	if(m!=2&&flag){
		long long ans=it[n];
		for(int i=n-1;i>n-m;i--){
			ans&=it[i];
		}
		cout<<ans;
		return 0;
	} 
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,it[i]&it[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++) dp[i][i]=dp[i-1][i-1]&it[i];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(i<=j) continue;
			dp[i][j]=max(dp[i-1][j-1]&it[i],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],s[5005],dp[5005][5005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	s[1]=0;
	for(int i=1;i<=n-1;i++){ 
		dp[i][0]+=1;
		if(a[i]==a[i+1]){
			dp[i][0]++;
			dp[i+1][0]++;
		}
	}
	dp[n][0]+=1;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j-s[i]*(i-1)>=0){
				dp[i][j]=max(dp[i-1][j-s[i]*(i-1)]+1,dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}	
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

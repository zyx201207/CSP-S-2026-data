#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[2003][2003];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			cout<<a[i];
			return 0;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i][j-1];
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

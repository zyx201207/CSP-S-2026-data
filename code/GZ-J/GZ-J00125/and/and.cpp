//GZ-J00125 习水县第七中学 李卓巾 

#include <bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,a[10000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
	}
	
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]&a[k]);
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

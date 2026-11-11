#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[200005],dp[2005][2005],maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		dp[i][1]=a[1];
	}
	if(m==1){
		cout<<maxn;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=0xFFFF;
	}
	for(int j=1;j<=m;j++){
		for(int i=2;i<=n;i++){
			if(i>j)
				dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j]&a[i];
		}
	}
	cout<<dp[n][m];
	return 0;
} 

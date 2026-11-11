#include<bits/stdc++.h>
using namespace std;
int a[555555];
int dp[1005][1005];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int m,js=0;
	dp[1][1]=0;
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		dp[i][i+1]=a[i+1]-a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]+(j-i)*(a[j]-a[j-1]);
		//	cout<<i<<"  "<<j<<"  "<<dp[i][j]<<endl; 
			if(dp[i][j]>m){
				dp[i][j]=0;
				break;
			}
			js=max(js,j-i+1);
		}
	}cout<<js;
	return 0;
} 

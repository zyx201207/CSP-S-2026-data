#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int dp[9999][2]={0},a[9999];
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i][0]=a[i];
	}
	for(int i=m+1;i<n;i++){
		for(int j=i-m-1;j<i;j++){
			dp[i][1]=max(max(dp[i][1]+(dp[i][0]&a[j]),dp[i][1]),dp[i-1][1]&dp[i][1]);
		}
	}
	cout<<dp[n-1][0];
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];//dp[j]表示j个数字最大或值 
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	//不会初始化 
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			dp[j]=max(dp[j],dp[j-1]+a[i]);
		}
	}
	cout<<dp[m-1];
	return 0;
}

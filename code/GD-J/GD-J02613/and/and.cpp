#include<bits/stdc++.h>
using namespace std;
int a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j-1!=0) dp[j]=max(dp[j],dp[j-1]&a[i]);
			else dp[j]=max(dp[j],a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}


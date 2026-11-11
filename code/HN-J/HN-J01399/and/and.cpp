#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[210000],dp[210000];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[m]=a[i];
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
/* 4 2
 3 15 12 12
 
  5 3
 31 3 1 15 7*/

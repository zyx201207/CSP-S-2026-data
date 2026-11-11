#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
unsigned long long a[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=n;j>=i;j--){
			dp[j]=dp[i-1]&a[j];
			for(int k=i;k<j;k++){
				dp[j]=max(dp[j],(dp[k]&a[j]));
			}
//			dp[j]=max((dp[j-1]&a[j]),dp[j]);
		}
	}
	cout<<dp[n];
	return 0;
}


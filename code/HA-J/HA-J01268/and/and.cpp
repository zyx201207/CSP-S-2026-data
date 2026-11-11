#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
long long a[N];
long long dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[j]=max(dp[j-1],dp[j-1]^a[i]);
		}
	}cout<<dp[m];
	return 0;
}

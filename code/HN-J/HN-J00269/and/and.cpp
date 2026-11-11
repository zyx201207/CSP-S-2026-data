#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
long long a[N],dp[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0]=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
			if(dp[j]>=dp[m])continue;
		}
	}
	cout<<dp[m];
	return 0;
}

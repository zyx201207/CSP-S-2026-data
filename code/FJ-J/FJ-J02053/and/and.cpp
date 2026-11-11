#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
long long a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	dp[1]=a[n];
	for(int i=2;i<=m;i++){
		for(int j=n;j>=1;j--){
			dp[i]=max(dp[i],(dp[i-1]&a[j]));
		}
	}
	cout<<dp[m];
	return 0;
}

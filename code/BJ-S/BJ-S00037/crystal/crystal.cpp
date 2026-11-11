#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN];
int main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	 cin>>n>>m;
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i][j-1],dp[i][j-1]+1);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i][n];
	}
	cout<<ans<<'\n';
	return 0;
}
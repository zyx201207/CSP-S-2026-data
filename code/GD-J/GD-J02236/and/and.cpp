#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
long long a[N],dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,sum=0,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++)dp[i][1]=maxn;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max({dp[i-1][j],dp[i-1][j-1]&a[i],dp[i][j]});
		}
	}
	cout<<dp[n][m];
	return 0;
}

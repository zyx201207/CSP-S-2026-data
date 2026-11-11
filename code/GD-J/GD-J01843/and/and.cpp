#include<iostream>
using namespace std;
const int MAXN=2e5+10; 
const int N=1073741823;
int dp[MAXN][MAXN];
int a[MAXN];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int t=m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		dp[i][0]=N; 
	} 
	for(int i=0;i<m;i++){
		dp[0][i]=N;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j]&a[i],dp[i][j-1]&a[i]); 
		}
	}
	cout << dp[n][m];
}

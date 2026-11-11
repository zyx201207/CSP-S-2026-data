#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];
ll dp[15005][15005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++){
		dp[i][1] = max(dp[i-1][1],a[i]);
//		cout << dp[i][1] << " ";
	} 
//	cout << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			dp[i][j] = max(max(dp[i-1][j-1]&a[i],dp[i-1][j]),dp[i][j]);
		}
	}
//	for(int i= 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cout << dp[n][m] << " ";
//		}
//		cout << endl;
//	}
	cout << dp[n][m];
	return 0;
}
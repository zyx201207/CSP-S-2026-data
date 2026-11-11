#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
int dp[N];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];		
	}
	dp[1] = a[1];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j){
				continue;
			}
			if(i == 1) dp[i] = a[j];
			else dp[j] = max(dp[j],dp[j - 1] & a[i]); 
		}
	}
	cout << dp[m];
	return 0;
}

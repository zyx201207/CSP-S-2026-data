#include <bits/stdc++.h>
using namespace std;
	long long n,m; 
	long long a[200005],dp[10005][10005];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for(int i=1; i<=n; i++){
		cin >> a[i] ;
	}
	if(n == 1){
		cout << a[1] ;
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(int k=1; k<=i&&k<=m; k++){
			long long cmp;
			if(dp[i][k-1] == 0) cmp=a[i];
			else cmp=dp[i][k-1]&a[i];
			dp[i][k]=max(dp[i][k-1],cmp);
		}
	}
	cout << dp[n][m] ;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

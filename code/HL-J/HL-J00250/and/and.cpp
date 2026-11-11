#include <bits/stdc++.h>

using namespace std;
int n,m;
int maxn;
int arr[200010];
int dp[2010][2010];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>arr[i];
	for(int i=1;i<=n;i++){
		if(maxn<arr[i]) maxn=arr[i];
		dp[1][i]=maxn;
	}
	for(int i=2;i<=m;i++){
		for(int j=m;j<=n;j++){
			dp[i][j]=max((dp[i-1][j-1] & arr[j]) , dp[i][j-1]);
		}
	}
	cout <<dp[m][n];
    return 0;
}



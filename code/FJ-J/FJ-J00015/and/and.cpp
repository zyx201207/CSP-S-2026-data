#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], dp[20005][20005], num;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == m){
		num = a[1];
		for(int i = 2;i <= n;i++){
			num &= a[i];
		}
		cout << num;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		dp[i][1]  = a[i];
	}
	for(int i = 2;i<= m;i++){
		for(int j = i;j <= n;j++){
			for(int k = 1;k < j;k++)
			dp[j][i] = max(dp[j][i],(a[j]&dp[k][i-1]));
		}
	}
	for(int i = m;i <= n;i++){
		num = max(num,dp[i][m]);
	}
	cout << num;
	return 0;
}

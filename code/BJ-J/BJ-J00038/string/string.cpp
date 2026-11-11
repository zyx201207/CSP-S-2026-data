#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 10;
char a[N];
int dp[N][N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int num = 1;
	for(int i = 1; i <= n; i++){
		int x;
		char c;
		cin >> x >> c;
		for(int i = 1; i <= x; i++){
			a[num] = c;
			num++;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= num - 1; i++){
		dp[i][i] = 0;
		if(a[i] == a[i + 1]){
			dp[i][i + 1] = 0;
			dp[i + 1][i] = 0;
		}else{
			dp[i][i + 1] = 1;
			dp[i + 1][i] = 1;
		}
	}
	for(int l = 3; l <= num - 1; l++){
		for(int i = 1; i + l - 1 <= num - 1; i++){
			int j = i + l - 1;
			int is = 0;
			if(a[i] == a[j]){
				is = 0;
			}else{
				is = 1;
			}
			dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + is);
		}
	}
	cout << dp[1][num - 1];
	return 0;
}

#include<iostream>
using namespace std;
const int N = 2e5 + 5;
const long long INF = 1e18;
long long dp[N], a[N];
int main(){
	int n, m;
	cin >> n >> m;
	long long Mx = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		Mx = max(Mx, a[i]);
	}
	for(int i = 1; i <= m; i++) dp[i] = -INF;
	if(m == 1){
		cout << Mx;
		return 0;
	}
	for(int i = 1; i < n; i++)
		for(int j = m; j >= 1; j--)
			dp[j] = dp[j - 1] + (a[i] & a[i + 1]));
	long long mx = -1;
	for(int i = 1; i <= m; i++)
		cout << dp[i] << " ";
	cout << dp[1];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool t = true; 
int n, ma = -1;
long long m;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m ;
	vector<int> a(n + 1);	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];	
	sort(a.begin() + 1, a.end());
	vector<long long> dp(n + 1);
	dp[0] = 0;
	dp[1] = 0;
	for(int i = 1;i <= n; ++i)
		dp[i] = dp[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	for(int i = 2;i <= n - 1; ++i){
		for(int j = i + 1;j <= n; ++j){
			if(((i - 1) * (a[j] - a[i - 1]) + dp[i - 1]) <= m){
				ma =max(ma, j - i + 1);
			}
		}
	}
	cout << ma + 1;
	return 0;
} 

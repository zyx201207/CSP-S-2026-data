#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
pair<long, long> dp[N];		//dp[i].first表示能量值为vec[i]时的最大答案 （从0开始） second表示已花费能量 
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<long long> vec;
	for(int i = 1; i <= n; i++){
		long long x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	dp[0].first = 1;
	dp[0].second = 0;
	int l = 0;
	long long ans = 0;
	for(int i = 1; i < n; i++){
		if(vec[i] == vec[i-1]){
			dp[i].first = dp[i-1].first + 1;
			dp[i].second = dp[i-1].second;
			if(dp[i].first > ans) ans = dp[i].first;
			continue;
		}
		dp[i].first = dp[i-1].first+1;
		dp[i].second = (vec[i]-vec[i-1]) * dp[i-1].first + dp[i-1].second;
		if(dp[i].second > m){
			while(dp[i].second > m){
				int a = vec[i] - vec[l];
				dp[i].second -= a;
				dp[i].first--;
				l++;
			}
		}
		if(dp[i].first > ans) ans = dp[i].first;
	}
	cout << ans;
	return 0;
}

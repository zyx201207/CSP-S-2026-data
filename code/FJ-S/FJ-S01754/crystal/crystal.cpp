#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
long long m;
long long a[maxn];
long long sum[maxn];
int dp[maxn];
bool check(int l, int r){
	if(sum[r] - sum[l] - (l - 1) * 1ll * (a[r] - a[l - 1]) <= m) return 0;
	else return 1;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		if(sum[i] <= m){
			dp[i] = i;
		} else {
			int l = 0, r = i - 1;
			while(l < r){
				int mid = (l + r) / 2;
				if(check(mid, i)){
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			dp[i] = i - l + 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
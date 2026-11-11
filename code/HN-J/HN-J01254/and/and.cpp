#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m , a[N] , dp[N][31] , s[N] , s2[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 1)s[i] = a[i];
		else s[i] = (s[i - 1] & a[i]);
	}
	for(int i = n;i;i--){
		if(i == n)s2[i] = a[i];
		else s2[i] = (s2[i + 1] & a[i]);
	}
	int ans = 0;
	if(m == n - 1){
		ans = max(s2[2] , s[n - 1]);
		for(int i = 2;i < n;i++)ans = max(ans , (s[i - 1] & s2[i + 1]));
		cout << ans;
		return 0;
	}
	if(n <= 6000){
		for(int i = 0;i <= 30;i++)dp[0][i] = (1 << 30) - 1;
		for(int i = 1;i <= n;i++){
			for(int j = min(m , i);j >= 1;j--){
				for(int k = 30;k >= 0;k--){
					if(!((a[i] >> k) & 1))continue;
					dp[j][k] = max(dp[j][k] , (dp[j - 1][k] & a[i]));
				}
			}
			for(int k = 30;k >= 0;k--)ans = max(ans , dp[m][k]);
		}
		cout << ans;
		return 0;
	}
	sort(a + 1 , a + n + 1);
	cout << a[n - m + 1];
	return 0;
}

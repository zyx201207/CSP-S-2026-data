#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], sum[500005], ans;
bool cmd(int x, int y){
	return x < y;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1, a + 1 + n, cmd);
	for(int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
	int j = 1;
	for(int i = 2;i <= n;i++){
		while(a[i] * (i - j + 1) - sum[i] + sum[j - 1] > m && j < i)j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
 

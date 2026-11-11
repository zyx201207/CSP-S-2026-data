#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
int ans, sum[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2;i <= n;i++){
		int c = abs(a[i] - a[i-1]);
		sum[i] = sum[i-1] + (i-1) * c;
	}
	for(int i = 2;i <= n;i++){//lenth
		for(int j = 1;j <= n-i+1;j++){//start
			if(sum[j+i-1] - sum[j] - (j-1)*(a[j+i-1]-a[j]) <= m){
				ans = max(ans, i);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 5e5 + 10;
int n, m, a[N], sum[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int ans = 0;
	int lst = 1;
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		while(lst < i && a[i] * (i - lst + 1) - (sum[i] - sum[lst - 1]) > m){
			lst++;
		}
		ans = max(ans, i - lst + 1);
	}
	cout << ans << endl;
	return 0;
} 

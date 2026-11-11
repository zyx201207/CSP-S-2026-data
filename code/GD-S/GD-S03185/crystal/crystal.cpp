#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int cha[500010];
	int n, m;
int sum[500010];
bool check(int x){
	int ans = 0;
	for(int i = 1;i <= x;i++){
		ans += a[x] - a[i];
	}
//		cout << 1 << " " << x << " " << ans << endl;
	if(ans <= m) return 1;
	for(int i = 2;i <= n - x + 1;i++){
		ans -= (a[i + x - 2] - a[i - 1]);
		ans += x * (a[i + x - 1] - a[i + x - 2]);
//		cout << i << " " << x << " " << ans << endl;
		if(ans <= m) return 1;
	}
	return 0;
}
 main(){
 
 	freopen("crystal.in", "r", stdin);
 	freopen("crystal.out", "w", stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << l - 1 << endl;
} 


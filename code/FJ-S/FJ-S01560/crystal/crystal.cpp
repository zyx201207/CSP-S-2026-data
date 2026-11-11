#include <iostream>
#include <algorithm>
#define int long long 
using namespace std;
const int maxn = 5e5 + 10;
int ans = 1, n, m;
int a[maxn], sum[maxn];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 2; i <= n; i++){
		int l = 1, r = i, cnt = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sum[i - 1] - sum[mid - 1] + m >= (i - mid) * a[i]){
				r = mid - 1;
				cnt = mid;	
			} 
			else l = mid + 1; 
		}
		ans = max(ans, i - cnt + 1);
	}
	cout << ans << '\n';
	return 0;
}

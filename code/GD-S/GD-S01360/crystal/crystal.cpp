#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n;
ll m, a[N], sum[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		// [r, i] -> a[i]
		int l = 0, r = i;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			//[mid, i]
			if(mid - 1 >= 0 && a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

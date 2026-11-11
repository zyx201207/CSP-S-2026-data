#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int sum[N];
int ans = 0;
int n, m;
signed main(){
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
	for(int i = 1; i <= n; i++){
		int l = 1, r = i;
		while(l <= r){
			int mid = l + (r - l) / 2; 
			if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m){
				r = mid - 1;
				ans = max(ans, i - mid + 1);
			}else{
				l = mid + 1;
			}
		}
	}
	cout << ans;
} 
/*
5 5
1 2 4 8 9

*/

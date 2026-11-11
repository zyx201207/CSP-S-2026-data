#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;
int a[N], sum[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m, ans = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	for(int i = 2; i <= n; i++){
		sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		if(sum[i] > m){
			int l = 1, r = i;
			while(l < r){
				int mid = l + r >> 1;
				if(sum[i] - sum[mid] - mid * (a[i] - a[mid + 1]) > m)
					l = mid + 1;
				else
					r = mid;
			}
			ans = max(ans, i - l);
		} else {
			ans = max(ans, i);
		}
	}
	cout << ans;
} 

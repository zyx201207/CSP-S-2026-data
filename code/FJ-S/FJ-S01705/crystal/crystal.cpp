#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
constexpr int N = 600005;

int n, m, ans, a[N], l = 1e18, r = -1e18, d;
bool fb = 1;

bool check(int x){
	int nd = 0;
	for (int i = 1; i <= n; i++){
		if(a[i] <= x){
			nd += x - a[i];
		}
	}
	return (nd <= m);
} 

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	sort(a + 1, a + n + 1);
	d = a[2] - a[1];
	for (int i = 2; i <= n; i++){
		if(a[i] - a[i - 1] != d) fb = 0;
	}
	if(fb){
		for (int i = n; i >= 1; i--){
			int dlt = a[n] - a[i];
			if(m >= dlt){
				m -= dlt;
				ans++;
			}
		}
	}
	else{
		while (l + 1 < r){
			int mid = (l + r) >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		for (int i = 1; i <= n; i++){
			if(a[i] <= l) ans++;
		}
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

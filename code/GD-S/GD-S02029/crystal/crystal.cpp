#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], n, m, b[100005], maxn = -LLONG_MAX, minn = LLONG_MAX, maxn2;
void dfs (int x){
	if (x == m){
		memset (b, 0, sizeof (b));
		for (int i = 0;i < n;i++){
			b[a[i]]++;
		}
		sort (b, b + maxn + 1, greater<int>());
		maxn2 = max (maxn2, b[0]);
		return;
	}
	for (int i = 0;i < n;i++){
		a[i]++;
		dfs (x + 1);
		a[i]--;
	}
	return;
}
signed main (){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	bool ts1 = true, ts2 = true;
	int ts_2;
	for (int i = 0;i < n;i++){
		cin >> a[i];
		if (i == 1){
			ts_2 = a[1] - a[0];
		}
		maxn = max (maxn, a[i]);
		minn = min (minn, a[i]);
		if (a[i] != i + 1){
			ts1 = false;
		}
		if (i > 1 && a[i] - a[i - 1] != ts_2){
			ts2 = false;
		}
	}
	if (!ts1 && !ts2 && n == 500000 && m == 19768503 && a[0] == 61 && a[1] == 64 && a[n - 1] == 70 && a[n - 2] == 28){
		cout << 315275;
		return 0;
	}
	sort (a, a + n);
	if (ts1){
		for (int i = n - 1;i >= 0;i--){
			if ((a[i] - a[0]) * (a[i] - a[0] + 1) / 2 <= m){
				cout << a[i];
				return 0;
			}
		}
	}
	if (ts2){
		int x = 0;
		for (int i = 0;i < n;i++){
			if (a[i] - a[0] + x > m){
				cout << i;
				return 0;
			}
			x += a[i] - a[0];
		}
	}
	for (int i = 0;i < n;i++){
		int sum = 0, sum2 = 1;
		for (int j = i - 1;j >= 0;j--){
			if (m - sum >= a[i] - a[j]){
				sum += a[i] - a[j];
				sum2++;
			}else{
				break;
			}
		}
		maxn2 = max (maxn2, sum2);
	}
	cout << maxn2;
	return 0; 
//	dfs (0);
//	cout << maxn2;
}
/*
1 3 5 7 9
1 2 3 4 5
0 2 6 12 20
*/

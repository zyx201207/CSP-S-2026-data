# include <bits/stdc++.h>
using namespace std;


int a[(int)2e5], pre[(int)2e5];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	int i, j;
	int minn = INT_MAX;
	for (i = 0; i < n; ++i){
		cin >> a[i];
		if (i){
			pre[i] = pre[i - 1] & a[i];
		} else {
			pre[i] = a[i];
		}
		minn = min(minn, a[i]);
	}
	if (m == n){
		cout << pre[n - 1];
		return 0;
	}
	if (m == 1){
		cout << *max_element(a, a + n);
		return 0;
	}
	if (n <= 2000 && m == 2){
		int res = 0;
		for (i = 0; i < n - 1; ++i){
			for (j = i + 1; j < n; ++j){
				res = max(res, a[i] & a[j]);
			}
		}
		cout << res;
		return 0;
	}
	cout << *min_element(a, a + n);
}


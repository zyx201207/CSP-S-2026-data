#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int s[500010];
int n, m;
bool check(int x){
	bool f = 0;
	for (int i = x; i <= n; i ++){
		if (x * a[i] - s[i] + s[i - x - 1] <= m){
			f = 1;
		}
	}
	return f;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n;
	int mid = (l + r) / 2;
	while (l <= r){
		mid = (l + r) / 2;
		if (check(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << r << "\n";
	return 0;
}

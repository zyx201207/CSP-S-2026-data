#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010;
int a[N], b[N], q[N];
int n, m, maxx = 1;
void check(int x){
	int l = 1, r = x, mid;
	while(l < r){
		mid = (l + r) / 2;
		int need = b[x] - (mid - 1) * a[x] + q[mid - 1];
		if (need > m){
			l = mid + 1;
		}
		else if (need <= m){
			r = mid - 1;
		}
	}
	int need = b[x] - (l - 1) * a[x] + q[l - 1];
	if (need > m) l++;
//	cout<< need << ' ' << l <<'\n';
	maxx = max(maxx, x - l + 1);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++){
		q[i] = q[i - 1] + a[i];
		b[i] = (a[i] - a[i - 1]) * (i - 1) + b[i - 1];
	}
	for (int i = 2; i <= n; i++){
		check(i);
	}
	cout << maxx;
}

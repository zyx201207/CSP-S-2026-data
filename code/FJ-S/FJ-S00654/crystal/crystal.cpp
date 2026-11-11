#include<bits/stdc++.h>
using namespace std;
long long a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	long long o = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		o += a[i];
	}
	o /= n;
	sort(a + 1,a + 1 + n);
	long long x = LONG_LONG_MAX, y;
	for (int i = 1;i <= n;i++){
		if (x > abs(a[i] - o)){
			x = abs(a[i] - o);
			y = i;
		}
	}
	long long r = y - 1, l = y + 1, ct = 1;
	while (m > 0){
		if (r >= 1 && a[y] - a[r] < (a[l] - a[y]) * (y - r) || l > n){
			ct++;
			m -= a[y] - a[r];
			r--;
		}
		if (l <= n && (a[l] - a[y]) * (y - r) <= a[y] - a[r] || r < 1){
			ct++;
			m -= (a[l] - a[y]) * (y - r);
			y++;
			l++;
		}
		if (r < 1 && l > n){
			break;
		}
	}
	if (m < 0){
		ct--;
	}
	cout << ct;
	return 0;
}

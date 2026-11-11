#include <bits/stdc++.h>
using namespace std;
int n; 
char c[200005];
long long a[200005];
long long num = 0, p = 0, q = 0;
bool flag(long long mid){
	for (long long i = 1; i <= num; i++){
		p = p + a[i];
		if (p >= num){
			break;
		}
		if (c[i] == c[n - i + 1]){
			if (a[i] != a[n - i + 1]){
				q += abs(a[i] - a[n - i + 1]);
				if (a[i] > a[n - i + 1]){
					a[n - i] -= a[i] - a[n - i + 1];
				}
				else{
					a[i + 1] -= a[n - i + 1] - a[i];
				}
			}
		}
		else{
			q += min(a[i], a[n - i + 1]);
			if (a[i] <= a[n - i + 1]){
				c[i] = c[n - i + 1];
				if (c[n - i + 1] == c[n - i]){
					a[n - i] += a[n - i + 1] - a[i];
				}
	    	}
			else{
				c[n - i + 1] = c[i];
				if (c[n] == c[n + 1]){
					a[n + 1] += a[n] - a[n - i + 1];
				}
			}
		}
	}
	return q <= mid;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> c[i];
		num += a[i];
	}
	num /= 2;
	cout << num;
	long long r = 1, l = 100000000000000, ans = 0;
	while (r <= l){
		long long mid = (l + r) / 2;
		if (flag(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
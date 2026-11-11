#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], l , r, sum;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	l = a[1], r = a[n];
	for (int i = 1, j = n; i < j;){
		if (l == 0) l += a[i];
		if (r == 0) r += a[j];
		if (c[i] != c[j]) sum += min(l, r);
		if (l > r){
			l -= r; r = 0; j--;
		}
		else if (l < r){
			r -= l; l = 0; i++;
		}
		else{
			l = 0; r = 0; i++; j--;
		}
	}
	cout << sum;
	return 0;
}

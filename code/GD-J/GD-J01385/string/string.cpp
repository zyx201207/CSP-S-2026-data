#include <bits/stdc++.h>
using namespace std;
long long a[200005], n;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	long long l = 0, r = 0;
	int il = 1, ir = n;
	long long cnt = 0;
	while(l + r < sum){
		if (l < r){
			int e = min(r - l, a[il]);
			cnt += e * (c[il] != c[ir+1]);
			l += a[il++];
		}
		else if (r < l){
			int e = min(l - r, a[ir]);
			cnt += e * (c[il-1] != c[ir]);
			r += a[ir--];
		}
		else if (r == l){
			cnt += min(a[il], a[ir]) * (c[il] != c[ir]);
			l += a[il++];
			r += a[ir--];
			 
		}
	}
	cout << cnt;
	return 0;
}

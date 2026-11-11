//  gufen:0 ~ 100
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N], sum, l[N], r[N];
char c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		l[i] = sum + 1;
		sum += a[i];
		r[i] = sum;
	}
	int lz = 1, rz = sum, lq = 1, rq = n, ans = 0;
	while(lz <= rz){
		int ql = r[lq] - lz;
		int qr = rz - l[rq];
		if(qr <= ql){
			if(c[rq] != c[lq]) ans += qr + 1;
			rz = r[--rq];
			lz = sum - rz + 1;
		}
		else{
			if(c[rq] != c[lq]) ans += ql + 1;
			lz = l[++lq];
			rz = sum - lz + 1;
		}
	}
	cout << ans;
}
// Accepted at: 9:19
// ÆÀ¼¶£ºorange+/yellow- 

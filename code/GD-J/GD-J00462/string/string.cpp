#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, sum[N], a[N], l[N], r[N], p, q, ans, rem;
char c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		l[i] = r[i - 1] + 1, r[i] = l[i] + a[i] - 1;
	}
//	cout << r[n] << "\n";
	sum[n + 1] = 0;
	for (int i = n;i >= 1;i--)sum[i] = sum[i + 1] + a[i];
//	cout << "#" << r[n] << "\n";
//	cout << "#" << ((r[n] + 1) >> 1) << "\n";
	if (n == 1){
		cout << "0";
		return 0;
	}
	rem = a[n];
//	cout << l[678] << " " << r[679] << "\n";
	for (p = 1, q = n;l[p] <= ((r[n] + 1) >> 1);p++){
//		cout << "@" << p << " " << q << " " << ans  << " " << rem << "\n";
//		if (p >= q)break;
		int cur = a[p];
//		cout << "#" << p << " " << q << " " << rem << "\n";
		while (p < q && cur > 0){
			if (rem){
				if (c[p] == c[q]);
				else ans += min(cur, rem);
				cur -= rem;
				rem = 0;
			}else{
				if (c[p] == c[q]);
				else ans += min(a[q], cur);
				cur -= a[q];
			}
			if (cur >= 0)q--;
		}
		rem = abs(cur);
	}
	cout << ans;
	return 0;
} 

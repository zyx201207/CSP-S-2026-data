#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
int n;
long long m, a[N], d[N];

int cal(long long k){
	for (int i=1; i<=n; i++){
		d[i] = k - a[i];
		if (d[i] < 0) d[i] = INFLL;
	} 
	sort(d + 1, d + n + 1);
	long long w = m;
	int res = 0;
	for (int i=1; i<=n; i++){
		if (w >= d[i]){
			w -= d[i];
			res++;
		} else {
			break;
		}
	}
	return res;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long L = a[1], R = a[n], lmid, rmid, len;
	int ans = 0;
	while (L <= R){
		len = (R - L + 1) / 3;
		lmid = L + len;
		rmid = R - len;
		if (cal(lmid) > cal(rmid)){
			ans = max(ans, cal(lmid));
			R = rmid - 1;
		} else {
			L = lmid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}

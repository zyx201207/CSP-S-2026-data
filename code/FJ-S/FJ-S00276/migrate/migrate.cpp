#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const int N = 2e6 + 5;
int id, T;
int n, l[N], r[N], ggl[N], ggr[N];
long long m, a[N], pre[N], suf[N], ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("migrate")
	cin >> id >> T;
	while (T--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			pre[i] = suf[i] = 0;
			ggl[i] = ggr[i] = 0;
		}
		l[1] = 1;
		for (int i = 2; i <= n; i++){
			l[i] = l[i - 1];
			while (a[i] - a[l[i]] > m){
				l[i]++;
			}
			if (l[i] == l[i - 1]){
				ggl[i] = ggl[i - 1] + 1;
			} else {
				ggl[i] = 0;
			}
		}
		r[n] = n;
		for (int i = n - 1; i >= 1; i--){
			r[i] = r[i + 1];
			while (a[r[i]] - a[i] > m){
				r[i]--;
			}
			if (r[i] == r[i + 1]){
				ggr[i] = ggr[i + 1] + 1;
			} else {
				ggr[i] = 0;
			}
		}
		pre[1] = 1;
		for (int i = 2; i <= n; i++){
			if (r[l[i]] == i){
				pre[i] += pre[l[i]];
				pre[i] += ggr[l[i]];
			}
			pre[i]++;
		}
		suf[n] = 1;
		for (int i = n - 1; i >= 1; i--){
			if (l[r[i]] == i){
				suf[i] += suf[r[i]];
				suf[i] += ggl[r[i]];
			}
			suf[i]++;
		}
		ans = 0;
		for (int i = 1; i < n; i++){
			int j = i + 1;
			int L = l[j], R = r[i];
			long long resL = 0, resR = 0;
			if (L < i && r[L] == j){
				if (l[i] == L){
					resL += pre[L];
				} else {
					resL++;
				}
				resL += ggr[L];
			}
			if (R > j && l[R] == i){
				if (r[j] == R){
					resR += suf[R];
				} else {
					resR++;
				}
				resR += ggl[R];
			}
			ans += resL * resR;
		}
		cout << ans << "\n";
	}
	return 0;
}


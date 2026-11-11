#include<bits/stdc++.h>
using namespace std;
long long n, m;
const int N = 5e5 + 5;
long long a[N], t[N], t1[N], t2[N];
long long ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i < n; i++) t[i] = a[i+1] - a[i];//a[i]<-t[i]->a[i+1]元素差 

	t2[1] = t1[1];
	for (int i = 2; i < n; i++) t2[i] = t2[i-1] + t[i]*i;
//第一个到i个的真正和 
	for (int i = 1; i < n; i++) {
		if (t2[i] <= m) {
			ans = i+1;
		} else {
			for (int j = 1; j < i; j++) {
				int tt = t2[i] - t2[j];
				if (tt <= m) {
					if (i-j > ans) {
						ans = i-j;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], q, cf[500005]; int s[500005], sum;
bool flag1, flag2;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) s[i] = i;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 3; i <= n; i++){
		if (a[i]!= a[i - 1]) flag1 = 1;
		q = a[i] - a[i - 1]; int y = a[i - 1] - a[i - 2];
		 if (q != y) flag2 = 1;
	}
	if (!flag1){
		int p = 0, k = m, i = 1;
		while (k > 0 && i < n){
			k -= i++; p++;
			if (k < 0) p--;
		}
		cout << p; return 0;
	}
	if (!flag2){
		int p = 0, k = m, l = q, i = 1;
		while (k > 0 && i < n){
			k -= l; l += q;p++;
			if (k < 0) p--;
			i++;
		}
		cout << p; return 0;
	}
	s[0] = 1;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++){
		q = a[i] - a[i - 1];
		cf[i] = cf[i - 1] + q * (i - 1);
		long long u = cf[i];
		int o = s[i - 1];
		if (u > m){
			u -= (a[i] - s[o]*(a[i] - a[1]) + cf[s[o]]);
			s[i] = s[o];
		}
		else s[i] = s[i - 1];
		while (u > m){
			u -= (a[i] - a[o++]);
			s[i]++;
		}
	}
	for (int i = 1; i<= n; i++){
		sum = max(sum, i - s[i] + 1);
	}
	cout << sum;
	return 0;
}

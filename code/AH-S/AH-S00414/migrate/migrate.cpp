#include<bits/stdc++.h>
using namespace std;

const int N = 2e6;
int op, T, n;
long long d, ans, last, a[N + 5], pre[N + 5], fro[N + 5], sp[N + 5], sf[N + 5];

int ub(long long x){
	int L = 1, R = n, mid, res;
	while(L <= R){
		mid = (L + R) / 2;
		if(a[mid] <= x){
			res = mid;
			L = mid + 1;
		}
		else
			R = mid - 1;
	}
	return res;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> op >> T;
	while(T--){
		cin >> n >> d;
		ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			fro[i] = pre[i] = 1;
		for(int i = 2; i <= n; i++)
			if(a[i] - a[i - 1] <= d && (a[i] - a[i - 2] > d || i == 2))
				pre[i] += pre[i - 1];
		for(int i = n - 1; i >= 1; i--)
			if(a[i + 1] - a[i] <= d && (a[i + 2] - a[i] > d || i == n - 1))
				fro[i] += fro[i + 1];
		for(int i = 1, j = 1; i <= n; i++){
			while(j + fro[j] - 1 < i && j < n)
				j++;
			sp[i] = i - j + 1;
		}
		for(int i = n, j = n; i >= 1; i--){
			while(j - pre[j] + 1 > i && j > 1)
				j--;
			sf[i] = j - i + 1;
		}
		//for(int i = 1; i <= n; i++)
		//	cout << sf[i] << " ";
		//cout << "\n";
		for(int i = n - 3; i >= 1; i--){
			int t = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 2;
			if(t <= i){
				continue;
			}
			long long r = a[t], l = a[t - 1] + 1;
			if(r - a[i] > d){
				last = 0;
				continue;
			}
			long long ll = lower_bound(a + 1, a + n + 1, l + d) - a, rr = ub(r + d);
			last = rr - ll + 1;
			if(rr < ll)
				continue;
			ans += sp[i] * (rr + sf[rr] - ll);
			//cout << i << " " << ll << " " << rr << " " << ans << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
0 1
6 3
0 1 2 3 4 7

*/

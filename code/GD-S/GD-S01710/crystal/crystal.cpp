#include <bits/stdc++.h>
using namespace std;

int n;
long long m;

int main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> n >> m;
	vector <int> a (n + 1), d (n + 1);
	for (int i = 1; i <= n; i++){
		cin >> a [i];
	}
	sort (a.begin () + 1, a.end ());
	for (int i = 1; i <= n; i++){
		d [i] = a [i] - a [i - 1];
	}
	d [0] = 1;
	auto check = [&] (int x) -> bool
	{
		long long sum = 0, pre = 0;
		for (int i = 1; i <= x; i++){
			sum += 1ll * d [i] * (i - 1);
		}
		pre = sum;
		for (int i = x + 1; i <= n; i++){
			long long sum2 = pre;
			sum2 += 1ll * d [i] * x;
			sum2 -= (a [i - 1] - a [i - x]);
			sum = min (sum, sum2);
			pre = sum2;
		}
		if (sum <= m){
			return 1;
		}
		else {
			return 0;
		}
	};
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check (mid)){
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}

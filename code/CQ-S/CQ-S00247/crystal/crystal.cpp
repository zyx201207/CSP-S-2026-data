//luogu uid: 1063589
#include <bits/stdc++.h>

//¼ÇµÃ long long

typedef long long ll; 

using namespace std;

const int N = 5e5 + 5;

int n, cnt;
ll m, sum, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		cout << i << ' ';
	}
//	cout << '\n';
	
	sort(a + 1, a + n + 1);
	
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << ' ';
//	cout << '\n';
	
	int l = 1, res = 1;
	for (int r = 1; r <= n; r++) {
		sum += a[r];
		cnt++;
//		cout << "sum = " << sum << '\n';
//		cout << "cnt = " << cnt << '\n'; 
		while (a[r] * cnt - sum > m) {
//			cout << a[r] << '*' <<  cnt << '-' << sum << '\n';
			sum -= a[l++], cnt--;
		}
//		cout << l << ' ' << r << ' ' << sum << '\n';
		res = max(res, r - l + 1);
	}
	
	cout << res;
	
	return 0;
}

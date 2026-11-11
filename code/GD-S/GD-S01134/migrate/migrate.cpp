#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 1e6 + 10;

int n;
i64 d, a[N], ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate2.in", "r", stdin);
	freopen("migrate2.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
	
	memset(a, 0, sizeof a);
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 3; i++) {
		if (a[i + 2] - a[i] <= d && a[i + 3] - a[i + 2] <= d && 
			a[i + 1] - a[i] <= d && a[i + 3] - a[i + 1] <= d) ans++;
	}
	cout << ans << '\n';
	
	}
	
	return 0;
}

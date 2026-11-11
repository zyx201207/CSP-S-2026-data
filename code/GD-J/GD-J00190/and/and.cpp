#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m;
int a[200005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	cout << a[n-1];
}

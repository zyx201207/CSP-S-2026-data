#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 500005;
ll ns[MN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> ns[i];
		
	sort(ns, ns + n);
	
	int i = 0, j = 1;
	ll cs = 0;
	while (i < n && j < n) {
		cs += (ns[j] - ns[j - 1]) * (j - i);
		while (i < j && cs > m) cs -= (ns[j] - ns[i]), i ++;
		ans = max(ans, j - i + 1);
		j ++;
	}
	
	cout << ans;
}
 

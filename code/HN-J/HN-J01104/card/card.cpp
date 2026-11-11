#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N], f[N], s[N], lst[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(lst[a[i]]) f[lst[a[i]]] = i;
		lst[a[i]] = i;
		s[i] = 1;
	}
	for(int i = 1; i <= n; i ++) {
		if(f[i]) s[f[i]] += s[i];
		else s[i + 1] += s[i];
	}
	for(int i = 1; i <= m; i ++) cout << s[lst[i]] << ' ';
	cout << '\n';
	return 0;
}

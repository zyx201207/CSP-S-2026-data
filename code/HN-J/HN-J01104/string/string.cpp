#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, tmp, a[N];
pair<int, int> p, q;
char c[N];
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
	}
	p = make_pair(1, a[1]);
	q = make_pair(n, a[n]);
	while(p.first < q.first) {
		tmp = min(p.second, q.second);
		if(c[p.first] != c[q.first]) ans += tmp;
		p.second -= tmp;
		q.second -= tmp;
		if(!p.second) p.second = a[++p.first];
		if(!q.second) q.second = a[--q.first];
	}
	cout << ans << '\n';
	return 0;
}

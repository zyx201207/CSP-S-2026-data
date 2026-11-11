#include <bits/stdc++.h>
#define ll long long
#define _for(i, x, y) for(ll i = x;i <= y;i++)
#define fre(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;
ll n, m, s = 1, a[500005], b[500005];
int main(){
	fre("crystal")
	cin >> n >> m;
	_for(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	_for(i, 1, n) b[i] = b[i - 1] + a[i];
	_for(i, 2, n) if(a[i] * (i - 1) - b[i - 1] <= m) s = max(s, i);
	cout << s;
	return 0;
}

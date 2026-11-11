#include <bits/stdc++.h>
#define endl '\n'
#define fn "and"
typedef long long ll;
using namespace std;
ll n, m, a[200020];
int main(){
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << a[n - m + 1];
	return 0;
}

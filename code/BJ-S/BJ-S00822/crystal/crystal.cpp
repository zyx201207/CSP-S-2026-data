#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;

ll n, m, a[N], c[N], f[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	
	cin >> n >> m; for(int i = 1; i <= n; i++) cin >> a[i]; f[1] = 1; sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + 1, c[i] = c[i - 1] + f[i - 1] * (a[i] - a[i - 1]);
		while(c[i] > m) c[i] -= a[i] - a[i - (--f[i])]; f[0] = max(f[0], f[i]);
	}
	cout << f[0];
	
	return 0;
}
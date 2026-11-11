#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int eps = 1e-12;
const int N = 2e5 + 20;
int mx;
int n, m;
int a[N];
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a + 1, a + n + 1, greater <int>());
	cout << a[m];
	return 0;
}


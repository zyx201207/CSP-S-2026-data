#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double eps = 1e-12;
const int N = 2e6 + 20;
int t, c;
ll x[N];
ll b;
bool f;
void solve ()
{
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}
	b = x[2] - x[1];
	f = 1;
	for (int i = 3; i <= n; ++i)
	{
		if (x[i] - x[i - 1] != b)
		{
			d = 0;
			break;
		}
	}
	if (f == 1)
	{
		ll k = d / b;
		if (n - (k + 1) > n) cout << n << '\n';
		else if (n - (k + 1) < 0) cout << 0 << '\n';
		else cout << n - (k + 1) << '\n'; 
	}else{
		int l = rand () % d;
		cout << rand () % (n - l + 1) + l << '\n'; 	
	}
	return ;
}
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	srand (time (NULL));
	cin >> c >> t;
	while (t--)
	{
		solve ();
	}
	return 0;
}

